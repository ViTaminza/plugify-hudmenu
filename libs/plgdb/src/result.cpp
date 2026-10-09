#include <plgdb/db.hpp>

#include <stdexcept>

namespace plgdb {

std::optional<size_t> Result::ColumnIndex(std::string_view name) const noexcept {
	for (size_t i = 0; i < columns.size(); ++i) {
		if (columns[i] == name) return i;
	}
	return std::nullopt;
}

const Value& Result::At(size_t row, size_t col) const {
	if (row >= rows.size() || col >= rows[row].size()) throw std::out_of_range("plgdb::Result::At");
	return rows[row][col];
}

bool Result::IsNull(size_t row, size_t col) const {
	return std::holds_alternative<std::monostate>(At(row, col));
}

int64_t Result::GetInt(size_t row, size_t col, int64_t def) const {
	const Value& v = At(row, col);
	if (auto p = std::get_if<int64_t>(&v)) return *p;
	if (auto p = std::get_if<double>(&v)) return static_cast<int64_t>(*p);
	if (auto p = std::get_if<std::string>(&v)) {
		try { return std::stoll(*p); } catch (...) { return def; }
	}
	return def;
}

double Result::GetDouble(size_t row, size_t col, double def) const {
	const Value& v = At(row, col);
	if (auto p = std::get_if<double>(&v)) return *p;
	if (auto p = std::get_if<int64_t>(&v)) return static_cast<double>(*p);
	if (auto p = std::get_if<std::string>(&v)) {
		try { return std::stod(*p); } catch (...) { return def; }
	}
	return def;
}

std::string Result::GetString(size_t row, size_t col, std::string def) const {
	const Value& v = At(row, col);
	if (auto p = std::get_if<std::string>(&v)) return *p;
	if (auto p = std::get_if<int64_t>(&v)) return std::to_string(*p);
	if (auto p = std::get_if<double>(&v)) return std::to_string(*p);
	return def;
}

} // namespace plgdb
