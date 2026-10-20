// plgdb: worker thread, FIFO queue, completion queue and the Database factory.

#include "internal.hpp"

#include <exception>
#include <utility>

namespace plgdb::detail {

namespace {

std::mutex g_loggerMutex;
std::function<void(std::string_view)> g_logger;

} // namespace

void SetLogger(std::function<void(std::string_view)> logger) {
	std::lock_guard<std::mutex> lock(g_loggerMutex);
	g_logger = std::move(logger);
}

void Log(std::string_view message) {
	std::function<void(std::string_view)> logger;
	{
		std::lock_guard<std::mutex> lock(g_loggerMutex);
		logger = g_logger;
	}
	if (logger) {
		try {
			logger(message);
		} catch (...) {
			// A logger must never take the database down.
		}
	}
}

DatabaseBase::~DatabaseBase() {
	StopWorker();
}

void DatabaseBase::StartWorker() {
	std::lock_guard<std::mutex> lock(queueMutex_);
	if (started_) return;
	started_ = true;
	worker_ = std::thread([this] { WorkerMain(); });
}

size_t DatabaseBase::Pending() const noexcept {
	return pending_.load(std::memory_order_relaxed);
}

void DatabaseBase::StopWorker() {
	{
		std::lock_guard<std::mutex> lock(queueMutex_);
		if (!worker_.joinable()) return; // already stopped (or never started)
		stopping_ = true;
	}
	queueCv_.notify_all();
	worker_.join();

	// Drop callbacks whose results arrived but were never polled. Per contract
	// they are discarded without being called.
	std::lock_guard<std::mutex> lock(completionMutex_);
	completions_.clear();
}

void DatabaseBase::Query(std::string sql, Params params, Callback callback) {
	Job job;
	job.sql = std::move(sql);
	job.params = std::move(params);
	job.callback = std::move(callback);
	{
		std::lock_guard<std::mutex> lock(queueMutex_);
		if (stopping_) return; // shutting down: silently drop the job
		queue_.push_back(std::move(job));
		pending_.fetch_add(1, std::memory_order_relaxed);
	}
	queueCv_.notify_one();
}

void DatabaseBase::Transaction(std::vector<Statement> statements, Callback callback) {
	Job job;
	job.isTransaction = true;
	job.statements = std::move(statements);
	job.callback = std::move(callback);
	{
		std::lock_guard<std::mutex> lock(queueMutex_);
		if (stopping_) return; // shutting down: silently drop the job
		queue_.push_back(std::move(job));
		pending_.fetch_add(1, std::memory_order_relaxed);
	}
	queueCv_.notify_one();
}

Result DatabaseBase::QuerySync(std::string sql, Params params) {
	auto slot = std::make_shared<SyncSlot>();
	{
		std::lock_guard<std::mutex> lock(queueMutex_);
		if (stopping_) {
			Result result;
			result.error = "plgdb: database is shutting down";
			return result;
		}
		Job job;
		job.sql = std::move(sql);
		job.params = std::move(params);
		job.sync = slot;
		queue_.push_back(std::move(job));
		pending_.fetch_add(1, std::memory_order_relaxed);
	}
	queueCv_.notify_one();

	// Safe to wait here even if Poll() is never called: the worker completes the
	// job independently. Calling QuerySync from inside a Poll() callback cannot
	// deadlock either — callbacks run on the caller thread, not on the worker.
	std::unique_lock<std::mutex> lock(slot->mutex);
	slot->cv.wait(lock, [&slot] { return slot->done; });
	return slot->result;
}

size_t DatabaseBase::Poll() {
	std::deque<Completion> batch;
	{
		std::lock_guard<std::mutex> lock(completionMutex_);
		batch.swap(completions_);
	}

	size_t ran = 0;
	for (Completion& completion : batch) {
		if (!completion.callback) continue;
		try {
			completion.callback(completion.result);
		} catch (const std::exception& e) {
			Log(std::string("plgdb: exception thrown by callback: ") + e.what());
		} catch (...) {
			Log("plgdb: unknown exception thrown by callback");
		}
		++ran;
	}
	return ran;
}

void DatabaseBase::WorkerMain() {
	for (;;) {
		Job job;
		{
			std::unique_lock<std::mutex> lock(queueMutex_);
			queueCv_.wait(lock, [this] { return stopping_ || !queue_.empty(); });
			if (queue_.empty()) break; // stopping_ && nothing left to flush
			job = std::move(queue_.front());
			queue_.pop_front();
		}

		Result result = RunJob(job);
		pending_.fetch_sub(1, std::memory_order_relaxed);

		if (job.sync) {
			{
				std::lock_guard<std::mutex> lock(job.sync->mutex);
				job.sync->result = std::move(result);
				job.sync->done = true;
			}
			job.sync->cv.notify_all();
		} else if (job.callback) {
			std::lock_guard<std::mutex> lock(completionMutex_);
			completions_.push_back(Completion{std::move(job.callback), std::move(result)});
		}
	}
}

Result DatabaseBase::RunJob(const Job& job) noexcept {
	try {
		if (job.isTransaction) return OnTransaction(job.statements);
		return OnQuery(job.sql, job.params);
	} catch (const std::exception& e) {
		Result result;
		result.error = std::string("plgdb: unhandled exception on worker thread: ") + e.what();
		Log(result.error);
		return result;
	} catch (...) {
		Result result;
		result.error = "plgdb: unhandled unknown exception on worker thread";
		Log(result.error);
		return result;
	}
}

} // namespace plgdb::detail

namespace plgdb {

std::unique_ptr<Database> Database::Create(const Config& config) {
	try {
		switch (config.driver) {
		case Driver::MySQL:
			if (config.host.empty() || config.database.empty()) return nullptr;
			return detail::MakeMySQLDatabase(config);
		case Driver::SQLite:
			if (config.sqlitePath.empty()) return nullptr;
			return detail::MakeSQLiteDatabase(config);
		}
	} catch (const std::exception& e) {
		// Never let construction (e.g. a failed thread spawn) throw into plugin code.
		detail::Log(std::string("plgdb: Database::Create failed: ") + e.what());
	} catch (...) {
		detail::Log("plgdb: Database::Create failed with an unknown exception");
	}
	return nullptr;
}

} // namespace plgdb
