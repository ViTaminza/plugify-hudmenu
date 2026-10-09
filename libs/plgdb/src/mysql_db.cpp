// plgdb MySQL driver: MariaDB Connector/C, real prepared statements on a worker thread.

#include "internal.hpp"

#include <mariadb/errmsg.h>
#include <mariadb/mysql.h>

#include <charconv>
#include <cstring>
#include <limits>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#ifndef MYSQL_DATA_TRUNCATED
#define MYSQL_DATA_TRUNCATED 101
#endif

namespace plgdb::detail {

namespace {

using StmtPtr = std::unique_ptr<MYSQL_STMT, decltype(&mysql_stmt_close)>;

std::string ConnErrorString(MYSQL* conn) {
	const unsigned int code = mysql_errno(conn);
	const char* msg = mysql_error(conn);
	return "plgdb(mysql): error " + std::to_string(code) + ": " + (msg && *msg ? msg : "unknown error");
}

std::string StmtErrorString(MYSQL_STMT* stmt) {
	const unsigned int code = mysql_stmt_errno(stmt);
	const char* state = mysql_stmt_sqlstate(stmt);
	const char* msg = mysql_stmt_error(stmt);
	std::string out = "plgdb(mysql): error " + std::to_string(code);
	if (state && *state && std::strcmp(state, "00000") != 0) {
		out += " (";
		out += state;
		out += ")";
	}
	out += ": ";
	out += (msg && *msg) ? msg : "unknown error";
	return out;
}

// Client-side codes >= 2000 plus SQLSTATE class 08 (connection exception).
bool IsConnectionError(unsigned int code, const char* sqlstate) {
	switch (code) {
	case CR_SERVER_GONE_ERROR: // 2006
	case CR_SERVER_LOST:       // 2013
	case CR_CONNECTION_ERROR:  // 2002
	case CR_CONN_HOST_ERROR:   // 2003
	case CR_UNKNOWN_HOST:      // 2005
	case 2055:                 // CR_SERVER_LOST_EXTENDED
		return true;
	default:
		break;
	}
	return sqlstate != nullptr && sqlstate[0] == '0' && sqlstate[1] == '8';
}

// Result columns are fetched as text (binary protocol + MYSQL_TYPE_STRING
// conversion, buffers sized from STMT_ATTR_UPDATE_MAX_LENGTH / fetch_column).
// Integers become int64_t, floating point and DECIMAL become double (DECIMAL is
// lossy for values that need more than double precision), everything else stays
// binary-safe text with embedded NULs preserved.
Value ConvertValue(const MYSQL_FIELD& field, std::string&& text) {
	const char* begin = text.data();
	const char* end = begin + text.size();
	switch (field.type) {
	case MYSQL_TYPE_TINY:
	case MYSQL_TYPE_SHORT:
	case MYSQL_TYPE_LONG:
	case MYSQL_TYPE_LONGLONG:
	case MYSQL_TYPE_INT24:
	case MYSQL_TYPE_YEAR: {
		int64_t out = 0;
		auto [ptr, ec] = std::from_chars(begin, end, out);
		if (ec == std::errc() && ptr == end) return out;
		if ((field.flags & UNSIGNED_FLAG) != 0) {
			uint64_t uout = 0;
			auto [uptr, uec] = std::from_chars(begin, end, uout);
			if (uec == std::errc() && uptr == end && uout <= static_cast<uint64_t>(std::numeric_limits<int64_t>::max())) {
				return static_cast<int64_t>(uout);
			}
		}
		return text; // out of int64 range: expose the value as text
	}
	case MYSQL_TYPE_FLOAT:
	case MYSQL_TYPE_DOUBLE:
	case MYSQL_TYPE_DECIMAL:
	case MYSQL_TYPE_NEWDECIMAL: {
		double out = 0.0;
		auto [ptr, ec] = std::from_chars(begin, end, out);
		if (ec == std::errc() && ptr == end) return out;
		return text;
	}
	default:
		return text;
	}
}

class MySQLDatabase final : public DatabaseBase {
public:
	explicit MySQLDatabase(const Config& config) : DatabaseBase(config) { StartWorker(); }
	~MySQLDatabase() override {
		StopWorker();
		CloseConnection();
	}

	Driver GetDriver() const noexcept override { return Driver::MySQL; }

protected:
	Result OnQuery(const std::string& sql, const Params& params) override {
		return RunStatement(sql, params, /*allowReconnect=*/true, nullptr);
	}

	Result OnTransaction(const std::vector<Statement>& statements) override {
		unsigned restarts = 0;
		for (;;) {
			Result begin = RunStatement("START TRANSACTION", {}, /*allowReconnect=*/true, nullptr);
			if (!begin.Ok()) return begin;

			bool restart = false;
			bool partial = false; // a data statement already ran: never retry after this
			Result last;
			for (const Statement& statement : statements) {
				bool lost = false;
				Result result = RunStatement(statement.sql, statement.params, /*allowReconnect=*/!partial, &lost);
				if (!result.Ok()) {
					// The transaction is dead either way; the rollback is best effort
					// (it fails too if the connection dropped).
					RunStatement("ROLLBACK", {}, /*allowReconnect=*/false, nullptr);
					if (lost && !partial && restarts < config().maxReconnectAttempts) {
						++restarts;
						restart = true; // nothing was done yet: safe to redo from BEGIN
					}
					last = std::move(result);
					break;
				}
				partial = true;
				last = std::move(result);
			}
			if (restart) {
				Log("plgdb(mysql): connection lost before any work, restarting transaction");
				continue;
			}
			if (!last.Ok()) return last;

			Result commit = RunStatement("COMMIT", {}, /*allowReconnect=*/false, nullptr);
			if (!commit.Ok()) {
				RunStatement("ROLLBACK", {}, /*allowReconnect=*/false, nullptr);
				return commit;
			}
			return last;
		}
	}

private:
	// Retries the statement after reconnecting up to config().maxReconnectAttempts
	// times when the failure is a lost/unavailable connection.
	Result RunStatement(const std::string& sql, const Params& params, bool allowReconnect, bool* connLostOut) {
		unsigned attempts = 0;
		for (;;) {
			if (conn_ == nullptr) {
				std::string err;
				if (!EnsureConnected(err)) {
					if (connLostOut) *connLostOut = true;
					if (!allowReconnect || attempts >= config().maxReconnectAttempts) {
						Result result;
						result.error = err;
						return result;
					}
					++attempts;
					continue;
				}
			}

			bool lost = false;
			Result result = RunStatementOnce(sql, params, lost);
			if (connLostOut) *connLostOut = lost;
			if (result.Ok() || !lost) return result;

			Log("plgdb(mysql): lost connection, reconnecting");
			CloseConnection();
			if (!allowReconnect || attempts >= config().maxReconnectAttempts) return result;
			++attempts;
		}
	}

	Result RunStatementOnce(const std::string& sql, const Params& params, bool& connLost) {
		Result result;
		connLost = false;

		if (sql.empty()) {
			result.error = "plgdb(mysql): empty statement";
			return result;
		}

		MYSQL_STMT* raw = mysql_stmt_init(conn_);
		if (raw == nullptr) {
			result.error = ConnErrorString(conn_);
			connLost = IsConnectionError(mysql_errno(conn_), mysql_sqlstate(conn_));
			return result;
		}
		StmtPtr stmt(raw, mysql_stmt_close);

		// Ask the connector to keep MYSQL_FIELD::max_length up to date so result
		// buffers can be sized exactly after mysql_stmt_store_result().
		my_bool updateMaxLength = 1;
		mysql_stmt_attr_set(stmt.get(), STMT_ATTR_UPDATE_MAX_LENGTH, &updateMaxLength);

		if (mysql_stmt_prepare(stmt.get(), sql.data(), static_cast<unsigned long>(sql.size())) != 0) {
			result.error = StmtErrorString(stmt.get());
			connLost = IsConnectionError(mysql_stmt_errno(stmt.get()), mysql_stmt_sqlstate(stmt.get()));
			return result;
		}

		const unsigned long paramCount = mysql_stmt_param_count(stmt.get());
		if (paramCount != params.size()) {
			result.error = "plgdb(mysql): statement expects " + std::to_string(paramCount) +
			               " parameters, " + std::to_string(params.size()) + " given";
			return result;
		}

		// The connector keeps a reference to the parameter bind array and to every
		// buffer it points at, so all of these must outlive mysql_stmt_execute().
		std::vector<MYSQL_BIND> paramBinds;
		std::vector<my_bool> paramNulls;
		std::vector<unsigned long> paramLengths;
		std::vector<int64_t> paramInts;
		std::vector<double> paramDoubles;
		std::vector<std::string> paramStrings;

		if (paramCount > 0) {
			paramBinds.resize(paramCount);
			paramNulls.assign(paramCount, 0);
			paramLengths.assign(paramCount, 0);
			paramInts.assign(paramCount, 0);
			paramDoubles.assign(paramCount, 0.0);
			paramStrings.reserve(paramCount); // keeps element addresses stable below

			for (size_t i = 0; i < params.size(); ++i) {
				MYSQL_BIND& bind = paramBinds[i];
				std::memset(&bind, 0, sizeof(bind));
				bind.is_null = &paramNulls[i];

				const Value& value = params[i];
				if (std::holds_alternative<std::monostate>(value)) {
					bind.buffer_type = MYSQL_TYPE_NULL;
				} else if (const auto* asInt = std::get_if<int64_t>(&value)) {
					paramInts[i] = *asInt;
					bind.buffer_type = MYSQL_TYPE_LONGLONG;
					bind.buffer = &paramInts[i];
					bind.buffer_length = sizeof(int64_t);
					bind.is_unsigned = 0;
				} else if (const auto* asDouble = std::get_if<double>(&value)) {
					paramDoubles[i] = *asDouble;
					bind.buffer_type = MYSQL_TYPE_DOUBLE;
					bind.buffer = &paramDoubles[i];
					bind.buffer_length = sizeof(double);
				} else {
					paramStrings.push_back(std::get<std::string>(value));
					const std::string& text = paramStrings.back();
					// Binary-safe: the length is always explicit, never strlen.
					// Strings are sent with the connection charset (so utf8mb4 text
					// into utf8mb4 columns needs no conversion); very large values
					// go as BLOB to avoid the 16-bit VARCHAR length class.
					bind.buffer_type = text.size() > 65535 ? MYSQL_TYPE_LONG_BLOB : MYSQL_TYPE_STRING;
					bind.buffer = const_cast<char*>(text.data());
					bind.buffer_length = static_cast<unsigned long>(text.size());
					bind.length = &paramLengths[i];
					paramLengths[i] = static_cast<unsigned long>(text.size());
				}
			}

			if (mysql_stmt_bind_param(stmt.get(), paramBinds.data()) != 0) {
				result.error = StmtErrorString(stmt.get());
				connLost = IsConnectionError(mysql_stmt_errno(stmt.get()), mysql_stmt_sqlstate(stmt.get()));
				return result;
			}
		}

		if (mysql_stmt_execute(stmt.get()) != 0) {
			result.error = StmtErrorString(stmt.get());
			connLost = IsConnectionError(mysql_stmt_errno(stmt.get()), mysql_stmt_sqlstate(stmt.get()));
			return result;
		}

		MYSQL_RES* rawMeta = mysql_stmt_result_metadata(stmt.get());
		if (rawMeta == nullptr) {
			if (mysql_stmt_field_count(stmt.get()) != 0) {
				result.error = StmtErrorString(stmt.get());
				connLost = IsConnectionError(mysql_stmt_errno(stmt.get()), mysql_stmt_sqlstate(stmt.get()));
				return result;
			}
			const my_ulonglong affected = mysql_stmt_affected_rows(stmt.get());
			result.affectedRows = (affected == static_cast<my_ulonglong>(-1)) ? 0 : static_cast<uint64_t>(affected);
			result.insertId = mysql_stmt_insert_id(stmt.get());
			return result;
		}
		std::unique_ptr<MYSQL_RES, decltype(&mysql_free_result)> meta(rawMeta, mysql_free_result);

		// store_result guarantees every row is available and makes
		// mysql_stmt_fetch_column for oversized values cheap and reliable.
		if (mysql_stmt_store_result(stmt.get()) != 0) {
			result.error = StmtErrorString(stmt.get());
			connLost = IsConnectionError(mysql_stmt_errno(stmt.get()), mysql_stmt_sqlstate(stmt.get()));
			return result;
		}

		const unsigned int fieldCount = mysql_num_fields(meta.get());
		MYSQL_FIELD* fields = mysql_fetch_fields(meta.get());

		result.columns.reserve(fieldCount);
		for (unsigned int i = 0; i < fieldCount; ++i) {
			result.columns.emplace_back(fields[i].name, fields[i].name_length);
		}

		struct ColumnBuffer {
			std::vector<char> text;
			unsigned long length = 0;
			my_bool isNull = 0;
			my_bool truncated = 0;
		};
		std::vector<ColumnBuffer> colBuffers(fieldCount);
		std::vector<MYSQL_BIND> resultBinds(fieldCount);
		for (unsigned int i = 0; i < fieldCount; ++i) {
			// max_length is filled in by store_result(); fall back to a modest
			// buffer and let the fetch_column path handle anything longer.
			const unsigned long maxLength = fields[i].max_length;
			const size_t size = maxLength > 0 ? maxLength : 256;
			colBuffers[i].text.resize(size);
			MYSQL_BIND& bind = resultBinds[i];
			std::memset(&bind, 0, sizeof(bind));
			bind.buffer_type = MYSQL_TYPE_STRING; // convert everything to text
			bind.buffer = colBuffers[i].text.data();
			bind.buffer_length = size;
			bind.length = &colBuffers[i].length;
			bind.is_null = &colBuffers[i].isNull;
			bind.error = &colBuffers[i].truncated;
		}
		if (mysql_stmt_bind_result(stmt.get(), resultBinds.data()) != 0) {
			result.error = StmtErrorString(stmt.get());
			connLost = IsConnectionError(mysql_stmt_errno(stmt.get()), mysql_stmt_sqlstate(stmt.get()));
			return result;
		}

		for (;;) {
			const int rc = mysql_stmt_fetch(stmt.get());
			if (rc == MYSQL_NO_DATA) break;
			if (rc != 0 && rc != MYSQL_DATA_TRUNCATED) {
				result.error = StmtErrorString(stmt.get());
				connLost = IsConnectionError(mysql_stmt_errno(stmt.get()), mysql_stmt_sqlstate(stmt.get()));
				result.rows.clear();
				return result;
			}

			std::vector<Value> row;
			row.reserve(fieldCount);
			for (unsigned int i = 0; i < fieldCount; ++i) {
				ColumnBuffer& buffer = colBuffers[i];
				if (buffer.isNull) {
					row.emplace_back(std::monostate{});
					continue;
				}
				if (buffer.truncated || buffer.length > buffer.text.size()) {
					// Long data: pull the full column value.
					std::string full;
					full.resize(buffer.length);
					MYSQL_BIND fetchBind;
					std::memset(&fetchBind, 0, sizeof(fetchBind));
					unsigned long fetched = buffer.length;
					my_bool fetchNull = 0;
					my_bool fetchError = 0;
					fetchBind.buffer_type = MYSQL_TYPE_STRING;
					fetchBind.buffer = full.data();
					fetchBind.buffer_length = buffer.length;
					fetchBind.length = &fetched;
					fetchBind.is_null = &fetchNull;
					fetchBind.error = &fetchError;
					if (mysql_stmt_fetch_column(stmt.get(), &fetchBind, i, 0) != 0 || fetchNull) {
						result.error = StmtErrorString(stmt.get());
						connLost = IsConnectionError(mysql_stmt_errno(stmt.get()), mysql_stmt_sqlstate(stmt.get()));
						result.rows.clear();
						return result;
					}
					full.resize(fetched);
					row.push_back(ConvertValue(fields[i], std::move(full)));
				} else {
					std::string text(buffer.text.data(), buffer.length);
					row.push_back(ConvertValue(fields[i], std::move(text)));
				}
			}
			result.rows.push_back(std::move(row));
		}

		const my_ulonglong affected = mysql_stmt_affected_rows(stmt.get());
		result.affectedRows = (affected == static_cast<my_ulonglong>(-1)) ? 0 : static_cast<uint64_t>(affected);
		result.insertId = mysql_stmt_insert_id(stmt.get());
		return result;
	}

	bool EnsureConnected(std::string& errOut) {
		if (conn_ != nullptr) return true;

		MYSQL* handle = mysql_init(nullptr);
		if (handle == nullptr) {
			errOut = "plgdb(mysql): mysql_init failed (out of memory)";
			return false;
		}

		unsigned int timeout = config().connectTimeoutSec;
		if (timeout == 0) timeout = 5;
		mysql_options(handle, MYSQL_OPT_CONNECT_TIMEOUT, &timeout);
		mysql_options(handle, MYSQL_OPT_READ_TIMEOUT, &timeout);
		mysql_options(handle, MYSQL_OPT_WRITE_TIMEOUT, &timeout);
		if (!config().charset.empty()) {
			mysql_options(handle, MYSQL_SET_CHARSET_NAME, config().charset.c_str());
		}

		if (mysql_real_connect(handle, config().host.c_str(), config().user.c_str(), config().password.c_str(),
		                       config().database.c_str(), config().port, nullptr, 0) == nullptr) {
			errOut = ConnErrorString(handle);
			mysql_close(handle);
			return false;
		}

		conn_ = handle;
		Log("plgdb(mysql): connected to " + config().host + ":" + std::to_string(config().port) + "/" + config().database);
		return true;
	}

	void CloseConnection() {
		if (conn_ == nullptr) return;
		mysql_close(conn_);
		conn_ = nullptr;
	}

	MYSQL* conn_ = nullptr; // owned by the worker thread
};

} // namespace

std::unique_ptr<Database> MakeMySQLDatabase(const Config& config) {
	return std::make_unique<MySQLDatabase>(config);
}

} // namespace plgdb::detail
