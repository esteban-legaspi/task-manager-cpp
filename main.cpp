#include <iostream>
#include "lib\sqlite3.h"

int main() {
    sqlite3* db;

    // Abrir o crear la base de datos
    if (sqlite3_open("test.db", &db) != SQLITE_OK) {
        std::cerr << "Error opening database\n";
        return 1;
    }

    // SQL simple
    const char* sql =
        "CREATE TABLE IF NOT EXISTS test ("
        "id INTEGER PRIMARY KEY, "
        "name TEXT);";

    // Ejecutar SQL
    if (sqlite3_exec(db, sql, nullptr, nullptr, nullptr) != SQLITE_OK) {
        std::cerr << "Error executing SQL\n";
        sqlite3_close(db);
        return 1;
    }

    std::cout << "SQLite is working correctly.\n";

    sqlite3_close(db);
    return 0;
}
