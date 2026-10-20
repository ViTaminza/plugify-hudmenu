#pragma once
// plgdb — async MySQL/SQLite access for Plugify C++ plugins (static library, linked into each plugin).
//
// Threading contract:
//   * Query()/Transaction() may be called from the game thread only; they never block.
//   * Each Database owns one worker thread that runs statements in FIFO order.
//   * Callbacks NEVER run on the worker thread: completed results are queued and executed
//     by Poll(), which the plugin calls from the game thread (e.g. OnPluginUpdate).
//   * QuerySync() blocks the caller; use it only for startup/migrations/tests.
//
// SQL contract:
//   * Parameters are bound with '?' placeholders for both drivers (real prepared statements,
//     no string interpolation). Never build SQL from user data.
//   * Value maps to SQL as: monostate -> NULL, int64_t -> BIGINT/INTEGER, double -> DOUBLE/REAL,
//     std::string -> TEXT/BLOB (binary-safe).

#include <cstdint>
#include <functional>
#include <memory>
#include <optional>
#include <string>
#include <string_view>
#include <utility>
#include <variant>
#include <vector>

namespace plgdb {

enum class Driver { MySQL, SQLite };

struct Config {
	Driver driver = Driver::SQLite;
	// MySQL
	std::string host = "127.0.0.1";
	uint16_t port = 3306;
	std::string user;
	std::string password;
	std::string database;
	std::string charset = "utf8mb4";
	unsigned connectTimeoutSec = 5;
	// SQLite
	std::string sqlitePath; // file path; ":memory:" allowed for tests
	// Both
	unsigned maxReconnectAttempts = 1; // per statement, on lost connection
};

using Value = std::variant<std::monostate, int64_t, double, std::string>;
using Params = std::vector<Value>;

class Result {
public:
	bool Ok() const noexcept { return error.empty(); }
	const std::string& Error() const noexcept { return error; }

	size_t RowCount() const noexcept { return rows.size(); }
	size_t ColumnCount() const noexcept { return columns.size(); }
	const std::vector<std::string>& Columns() const noexcept { return columns; }
	std::optional<size_t> ColumnIndex(std::string_view name) const noexcept;

	const Value& At(size_t row, size_t col) const; // throws std::out_of_range
	bool IsNull(size_t row, size_t col) const;
	int64_t GetInt(size_t row, size_t col, int64_t def = 0) const;
	double GetDouble(size_t row, size_t col, double def = 0.0) const;
	std::string GetString(size_t row, size_t col, std::string def = {}) const;

	uint64_t AffectedRows() const noexcept { return affectedRows; }
	uint64_t InsertId() const noexcept { return insertId; }

	// Filled by the implementation.
	std::string error;
	std::vector<std::string> columns;
	std::vector<std::vector<Value>> rows;
	uint64_t affectedRows = 0;
	uint64_t insertId = 0;
};

using Callback = std::function<void(const Result&)>;

struct Statement {
	std::string sql;
	Params params;
};

class Database {
public:
	// Connects lazily on the worker thread; returns nullptr only for an invalid config.
	static std::unique_ptr<Database> Create(const Config& config);
	virtual ~Database() = default; // flushes pending work, joins the worker

	virtual Driver GetDriver() const noexcept = 0;

	virtual void Query(std::string sql, Params params, Callback callback = {}) = 0;
	// All statements in one transaction; on the first error everything is rolled back and the
	// callback receives that error. On success the callback receives the LAST statement's result.
	// A lost connection never reconnects in the middle of a transaction (the new session would
	// be in autocommit mode and the caller would get a false success): the transaction is
	// redone from the start while nothing has completed, otherwise the callback gets the error.
	virtual void Transaction(std::vector<Statement> statements, Callback callback = {}) = 0;

	virtual Result QuerySync(std::string sql, Params params = {}) = 0;

	// Runs completed callbacks on the calling thread. Returns how many ran.
	virtual size_t Poll() = 0;

	// Number of statements queued or running on the worker.
	virtual size_t Pending() const noexcept = 0;
};

} // namespace plgdb
