#pragma once
#include <string>
#include <sqlite3.h>

class SQLiteLogger {
public:
    SQLiteLogger(const std::string& db_path);
    ~SQLiteLogger();
    void insert_price(double price);

private:
    sqlite3* db;
};
