#include "sqlite_logger.hpp"
#include <iostream>

SQLiteLogger::SQLiteLogger(const std::string& db_path) {
    if (sqlite3_open(db_path.c_str(), &db)) {
        std::cerr << "Can't open DB: " << sqlite3_errmsg(db) << std::endl;
        db = nullptr;
    } else {
        const char* sql = "CREATE TABLE IF NOT EXISTS price_history ("
                          "timestamp DATETIME DEFAULT CURRENT_TIMESTAMP,"
                          "price REAL);";
        char* errMsg;
        if (sqlite3_exec(db, sql, nullptr, nullptr, &errMsg) != SQLITE_OK) {
            std::cerr << "SQL error: " << errMsg << std::endl;
            sqlite3_free(errMsg);
        }
    }
}

SQLiteLogger::~SQLiteLogger() {
    if (db) sqlite3_close(db);
}

void SQLiteLogger::insert_price(double price) {
    if (!db) return;
    std::string sql = "INSERT INTO price_history (price) VALUES (" + std::to_string(price) + ");";
    char* errMsg;
    if (sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg) != SQLITE_OK) {
        std::cerr << "SQL insert error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}
