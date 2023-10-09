#pragma once

#include <string>
#include <vector>

class SqlSelectQueryBuilder {
private:
    std::vector<std::string> columns;
    std::string fromTable;
    std::vector<std::string> whereConditions;

public:
    SqlSelectQueryBuilder();

    SqlSelectQueryBuilder& AddColumn(const std::string& column);
    SqlSelectQueryBuilder& AddFrom(const std::string& table);
    SqlSelectQueryBuilder& AddWhere(const std::string& column, const std::string& value);
    std::string BuildQuery() const;
};

