#pragma once

#include <string>
#include <vector>
#include <map>

class SqlSelectQueryBuilder {
private:
    std::vector<std::string> columns;
    std::string fromTable;
    std::vector<std::string> whereConditions;

public:
    SqlSelectQueryBuilder();

    SqlSelectQueryBuilder& AddColumn(const std::string& column);
    SqlSelectQueryBuilder& AddColumns(const std::vector<std::string>& columns) noexcept;
    SqlSelectQueryBuilder& AddFrom(const std::string& table);
    SqlSelectQueryBuilder& AddWhere(const std::string& column, const std::string& value);
    SqlSelectQueryBuilder& AddWhere(const std::map<std::string, std::string>& kv) noexcept;
    std::string BuildQuery() const;
};

