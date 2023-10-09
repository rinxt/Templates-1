#include "sql_query_builder.h"

SqlSelectQueryBuilder::SqlSelectQueryBuilder() {}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumn(const std::string& column) {
    columns.push_back(column);
    return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddFrom(const std::string& table) {
    fromTable = table;
    return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(const std::string& column, const std::string& value) {
    std::string condition = column + "=" + value;
    whereConditions.push_back(condition);
    return *this;
}

std::string SqlSelectQueryBuilder::BuildQuery() const {
    std::string query = "SELECT ";
    if (columns.empty()) {
        query += "*";
    }
    else {
        for (size_t i = 0; i < columns.size(); ++i) {
            query += columns[i];
            if (i < columns.size() - 1) {
                query += ", ";
            }
        }
    }

    query += " FROM " + fromTable;

    if (!whereConditions.empty()) {
        query += " WHERE ";
        for (size_t i = 0; i < whereConditions.size(); ++i) {
            query += whereConditions[i];
            if (i < whereConditions.size() - 1) {
                query += " AND ";
            }
        }
    }

    query += ";";
    return query;
}
