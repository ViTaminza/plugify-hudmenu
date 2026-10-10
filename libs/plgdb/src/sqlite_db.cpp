// plgdb SQLite driver: sqlite3, prepared statements on a worker thread.

#include "internal.hpp"

#include <sqlite3.h>

#include <cctype>
#include <cstring>
#include <filesystem>
#include <system_error>
#include <memory>
#include <string>
#include <utility>
#include <vector>

namespace plgdb::detail {

namespace {

using StmtPtr = std::unique_ptr<sqlite3_stmt, decltype(&sqlite3_finalize)>;

bool IsMemoryPath(const std::string& path) {
	return path == ":memory:" || path.rfind("file::memory:", 0) == 0;
}

class SQLiteDatabase final : public DatabaseBase {
public:
	explicit SQLiteDatabase(const Config& config) : DatabaseBase(config) { StartWorker(); }
	~SQLiteDatabase() override {
		StopWorker();
		Close();
	}

	Driver GetDriver() const noexcept override { return Driver::SQLite; }

protected:
	Result OnQuery(const std::string& sql, const Params& params) override {
		Result result;
		std::string err;
		if (!EnsureOpen(err)) {
			result.error = err;
			return result;
		}
		return Exec(sql, params);
	}

	Result OnTransaction(const std::vector<Statement>& statements) override {
		Result result;
		std::string err;
		if (!EnsureOpen(err)) {
			result.error = err;
			return result;
		}

		Result begun = Exec("BEGIN", {});
		if (!begun.Ok()) return begun;

		Result last;
		for (const Statement& statement : statements) {
			Result current = Exec(statement.sql, statement.params);
			if (!current.Ok()) {
				Rollback();
				return current;
			}
			last = std::move(current);
		}

		Result committed = Exec("COMMIT", {});
		if (!committed.Ok()) {
			Rollback();
			return committed;
		}
		return last;
	}

private:
	bool EnsureOpen(std::string& errOut) {
		if (db_ != nullptr) return true;

		const std::string& path = config().sqlitePath;
		sqlite3* handle = nullptr;
		if (path != ":memory:" && path.rfind("file:", 0) != 0) {
			// Create the parent directory of a file database (plugin data dirs may not exist yet).
			std::error_code ec;
			const std::filesystem::path parent = std::filesystem::path(path).parent_path();
			if (!parent.empty()) {
				std::filesystem::create_directories(parent, ec);
			}
		}
		const int rc = sqlite3_open_v2(path.c_str(), &handle, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE | SQLITE_OPEN_FULLMUTEX, nullptr);
		if (rc != SQLITE_OK) {
			errOut = std::string("plgdb(sqlite): cannot open ") + path + ": " + (handle ? sqlite3_errmsg(handle) : sqlite3_errstr(rc));
			if (handle != nullptr) sqlite3_close(handle);
			return false;
		}

		sqlite3_busy_timeout(handle, 5000);
		if (!IsMemoryPath(path)) {
			// WAL is persistent per database file; ignore failures (e.g. read-only
			// filesystems keep the rollback journal, which still works).
			char* message = nullptr;
			if (sqlite3_exec(handle, "PRAGMA journal_mode=WAL;", nullptr, nullptr, &message) != SQLITE_OK) {
				Log(std::string("plgdb(sqlite): PRAGMA journal_mode=WAL failed: ") + (message ? message : "unknown error"));
			}
			sqlite3_free(message);
		}

		db_ = handle;
		return true;
	}

	void Close() {
		if (db_ == nullptr) return;
		sqlite3_close(db_);
		db_ = nullptr;
	}

	void Rollback() {
		if (db_ == nullptr) return;
		sqlite3_exec(db_, "ROLLBACK", nullptr, nullptr, nullptr);
	}

	Result Exec(const std::string& sql, const Params& params) {
		Result result;
		if (sql.empty()) {
			result.error = "plgdb(sqlite): empty statement";
			return result;
		}

		sqlite3_stmt* raw = nullptr;
		const char* tail = nullptr;
		const int prepareRc = sqlite3_prepare_v2(db_, sql.c_str(), static_cast<int>(sql.size()), &raw, &tail);
		if (prepareRc != SQLITE_OK) {
			result.error = std::string("plgdb(sqlite): prepare failed: ") + sqlite3_errmsg(db_);
			return result;
		}
		if (raw == nullptr) {
			result.error = "plgdb(sqlite): statement contains no SQL";
			return result;
		}
		StmtPtr stmt(raw, sqlite3_finalize);

		if (tail != nullptr) {
			for (const char* p = tail; *p != '\0'; ++p) {
				if (*p != ';' && !std::isspace(static_cast<unsigned char>(*p))) {
					result.error = "plgdb(sqlite): multiple statements in one call are not supported";
					return result;
				}
			}
		}

		const int paramCount = sqlite3_bind_parameter_count(stmt.get());
		if (paramCount != static_cast<int>(params.size())) {
			result.error = "plgdb(sqlite): statement expects " + std::to_string(paramCount) + " parameters, " +
			               std::to_string(params.size()) + " given";
			return result;
		}

		for (int i = 0; i < paramCount; ++i) {
			const Value& value = params[static_cast<size_t>(i)];
			int rc = SQLITE_OK;
			if (std::holds_alternative<std::monostate>(value)) {
				rc = sqlite3_bind_null(stmt.get(), i + 1);
			} else if (const auto* asInt = std::get_if<int64_t>(&value)) {
				rc = sqlite3_bind_int64(stmt.get(), i + 1, *asInt);
			} else if (const auto* asDouble = std::get_if<double>(&value)) {
				rc = sqlite3_bind_double(stmt.get(), i + 1, *asDouble);
			} else {
				const std::string& text = std::get<std::string>(value);
				// Explicit byte length keeps embedded NULs (binary-safe).
				rc = sqlite3_bind_text(stmt.get(), i + 1, text.data(), static_cast<int>(text.size()), SQLITE_TRANSIENT);
			}
			if (rc != SQLITE_OK) {
				result.error = std::string("plgdb(sqlite): bind failed: ") + sqlite3_errmsg(db_);
				return result;
			}
		}

		const int columnCount = sqlite3_column_count(stmt.get());
		if (columnCount > 0) {
			result.columns.reserve(static_cast<size_t>(columnCount));
			for (int i = 0; i < columnCount; ++i) {
				const char* name = sqlite3_column_name(stmt.get(), i);
				result.columns.emplace_back(name ? name : "");
			}

			for (;;) {
				const int stepRc = sqlite3_step(stmt.get());
				if (stepRc == SQLITE_DONE) break;
				if (stepRc != SQLITE_ROW) {
					result.error = std::string("plgdb(sqlite): step failed: ") + sqlite3_errmsg(db_);
					result.rows.clear();
					return result;
				}

				std::vector<Value> row;
				row.reserve(static_cast<size_t>(columnCount));
				for (int i = 0; i < columnCount; ++i) {
					switch (sqlite3_column_type(stmt.get(), i)) {
					case SQLITE_INTEGER:
						row.emplace_back(static_cast<int64_t>(sqlite3_column_int64(stmt.get(), i)));
						break;
					case SQLITE_FLOAT:
						row.emplace_back(sqlite3_column_double(stmt.get(), i));
						break;
					case SQLITE_TEXT: {
						const unsigned char* text = sqlite3_column_text(stmt.get(), i);
						const int bytes = sqlite3_column_bytes(stmt.get(), i);
						row.emplace_back(text != nullptr
						                     ? std::string(reinterpret_cast<const char*>(text), bytes > 0 ? static_cast<size_t>(bytes) : 0)
						                     : std::string());
						break;
					}
					case SQLITE_BLOB: {
						const void* blob = sqlite3_column_blob(stmt.get(), i);
						const int bytes = sqlite3_column_bytes(stmt.get(), i);
						if (blob != nullptr && bytes > 0) {
							row.emplace_back(std::string(static_cast<const char*>(blob), static_cast<size_t>(bytes)));
						} else {
							row.emplace_back(std::string());
						}
						break;
					}
					default: // SQLITE_NULL
						row.emplace_back(std::monostate{});
						break;
					}
				}
				result.rows.push_back(std::move(row));
			}
		} else {
			const int stepRc = sqlite3_step(stmt.get());
			if (stepRc != SQLITE_DONE) {
				result.error = std::string("plgdb(sqlite): step failed: ") + sqlite3_errmsg(db_);
				return result;
			}
			result.affectedRows = static_cast<uint64_t>(sqlite3_changes(db_));
			result.insertId = static_cast<uint64_t>(sqlite3_last_insert_rowid(db_));
		}
		return result;
	}

	sqlite3* db_ = nullptr; // owned by the worker thread
};

} // namespace

std::unique_ptr<Database> MakeSQLiteDatabase(const Config& config) {
	return std::make_unique<SQLiteDatabase>(config);
}

} // namespace plgdb::detail
