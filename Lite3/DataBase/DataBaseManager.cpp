#include "DataBaseManager.h"
#ifdef __SQLDatabaseManager__
#include <filesystem>

SQLDatabaseManager::~SQLDatabaseManager()
{
    if (db)
        sqlite3_close(db);
}

bool SQLDatabaseManager::createDatabase(const std::string &dbName)
{
    if (sqlite3_open(dbName.c_str(), &db) != SQLITE_OK)
        return false;

    const char *createTable = R"(
            CREATE TABLE IF NOT EXISTS )" __TABLE_NAME__ R"((
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                full_name TEXT NOT NULL,
                phone_number TEXT UNIQUE NOT NULL,
                note TEXT
            );
        )";

    return sqlite3_exec(db, createTable, nullptr, nullptr, nullptr) == SQLITE_OK;
}

bool SQLDatabaseManager::deleteDatabase(const std::string &dbName)
{
    if (db)
        sqlite3_close(db);
    db = nullptr;
    return std::filesystem::remove(dbName);
}

#endif