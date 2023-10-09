#include "sql_query_builder.h"
#include <iostream>
#include <cassert>

int main() {
    SqlSelectQueryBuilder query_builder;
    query_builder.AddColumn("name").AddColumn("phone");
    query_builder.AddWhere("surname", "Smit").AddWhere("name", "John");
    query_builder.AddFrom("students");


    std::string expected_query = "SELECT name, phone FROM students WHERE surname=Smit AND name=John;";
    std::string query = query_builder.BuildQuery();

    std::cout << "Generated query: " << query << std::endl;
    std::cout << "Expected query: " << expected_query << std::endl;

    assert(query == expected_query && "Generated query does't match expected query!");
    std::cout << "Test passed successfully!" << std::endl;

    return 0;
}
