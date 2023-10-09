#include "sql_query_builder.h"
#include <iostream>
#include <cassert>

int main() {
    SqlSelectQueryBuilder query_builder;
    query_builder.AddColumns({ "name", "phone" });
    query_builder.AddFrom("students");
    std::map<std::string, std::string> additional_conditions = {
        {"surname", "Smit"},
        {"gender", "male"}
    };
    query_builder.AddWhere(additional_conditions);

    std::string expected_query = "SELECT name, phone FROM students WHERE gender=male AND surname=Smit;";
    std::string query = query_builder.BuildQuery();

    std::cout << "Generated query: " << query << std::endl;
    std::cout << "Expected query: " << expected_query << std::endl;

    assert(query == expected_query && "Generated query does't match expected query!");
    std::cout << "Test passed successfully!" << std::endl;

    return 0;
}
