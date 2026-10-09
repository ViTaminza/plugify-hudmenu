#pragma once
// plgdb internals: shared worker/queue base class and driver factories.
// NOT a public header — the public API is <plgdb/db.hpp> only.

#include <plgdb/db.hpp>

#include <atomic>
#include <condition_variable>
#include <cstddef>
#include <deque>
#include <functional>
#include <memory>
#include <mutex>
#include <string>
#include <string_view>
#include <thread>
#include <utility>
#include <vector>

namespace plgdb::detail {

// Optional logging hook for internal diagnostics (worker-side exceptions,
// exceptions thrown by user callbacks, reconnects). Thread-safe; pass an empty
// std::function to clear it. Never called with the completion lock held.
void SetLogger(std::function<void(std::string_view)> logger);
void Log(std::string_view message);

// Common plumbing for both drivers:
//   * one worker thread started by StartWorker() (called from the concrete
//     driver's constructor, after its own members exist),
//   * FIFO job queue (mutex + condvar),
//   * completion queue drained by Poll() on the caller thread,
//   * StopWorker(): stop accepting work, drain the queue (flush), join, then
//     discard completions that were never polled (those callbacks are dropped
//     without being called).
class DatabaseBase : public Database {
public:
	explicit DatabaseBase(Config config) : config_(std::move(config)) {}
	~DatabaseBase() override;

	void Query(std::string sql, Params params, Callback callback) override;
	void Transaction(std::vector<Statement> statements, Callback callback) override;
	Result QuerySync(std::string sql, Params params) override;
	size_t Poll() override;
	size_t Pending() const noexcept override;

protected:
	const Config& config() const noexcept { return config_; }

	// Idempotent. Starting with no jobs queued and stopping with an empty queue
	// are both no-ops.
	void StartWorker();
	void StopWorker();

	// Called on the worker thread only. Implementations must not let exceptions
	// escape (DatabaseBase catches anyway, but Result.error is the contract).
	virtual Result OnQuery(const std::string& sql, const Params& params) = 0;
	virtual Result OnTransaction(const std::vector<Statement>& statements) = 0;

private:
	struct SyncSlot {
		std::mutex mutex;
		std::condition_variable cv;
		bool done = false;
		Result result;
	};

	struct Job {
		bool isTransaction = false;
		std::string sql;
		Params params;
		std::vector<Statement> statements;
		Callback callback;
		std::shared_ptr<SyncSlot> sync; // QuerySync: result goes here, no callback
	};

	struct Completion {
		Callback callback;
		Result result;
	};

	void WorkerMain();
	Result RunJob(const Job& job) noexcept;

	Config config_;
	std::thread worker_;
	std::mutex queueMutex_;
	std::condition_variable queueCv_;
	std::deque<Job> queue_;
	bool stopping_ = false; // guarded by queueMutex_
	bool started_ = false;  // guarded by queueMutex_
	std::mutex completionMutex_;
	std::deque<Completion> completions_;
	std::atomic<size_t> pending_{0};
};

std::unique_ptr<Database> MakeMySQLDatabase(const Config& config);
std::unique_ptr<Database> MakeSQLiteDatabase(const Config& config);

} // namespace plgdb::detail
