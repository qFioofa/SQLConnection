#include "TableCleaner.h"
#include <vector>

SQLTableCleaner::SQLTableCleaner(SQLDatabaseManager &manager, std::string table)
    : db(manager.getHandle()), tableName(std::move(table)) {}

bool SQLTableCleaner::truncateTable()
{
        if (!db)
                return false;

        std::string query = "DELETE FROM " + tableName + ";";
        char *errMsg = nullptr;

        bool success = sqlite3_exec(db, query.c_str(), nullptr, nullptr, &errMsg) == SQLITE_OK;
        if (errMsg)
                sqlite3_free(errMsg);

        return success;
}

bool SQLTableCleaner::resetTable()
{
        if (!db)
                return false;

        std::string schemaQuery = "SELECT sql FROM sqlite_master WHERE type='table' AND name=?;";
        sqlite3_stmt *stmt;
        std::string createStmt;

        sqlite3_prepare_v2(db, schemaQuery.c_str(), -1, &stmt, nullptr);
        sqlite3_bind_text(stmt, 1, tableName.c_str(), -1, SQLITE_TRANSIENT);

        if (sqlite3_step(stmt) == SQLITE_ROW)
        {
                createStmt = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0));
        }
        sqlite3_finalize(stmt);

        if (createStmt.empty())
                return false;

        bool success = true;
        sqlite3_exec(db, "BEGIN TRANSACTION;", nullptr, nullptr, nullptr);

        std::string dropQuery = "DROP TABLE " + tableName + ";";
        success &= sqlite3_exec(db, dropQuery.c_str(), nullptr, nullptr, nullptr) == SQLITE_OK;

        success &= sqlite3_exec(db, createStmt.c_str(), nullptr, nullptr, nullptr) == SQLITE_OK;

        if (success)
        {
                sqlite3_exec(db, "COMMIT;", nullptr, nullptr, nullptr);
        }
        else
        {
                sqlite3_exec(db, "ROLLBACK;", nullptr, nullptr, nullptr);
        }

        return success;
}