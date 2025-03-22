#include "DataUpdater.h"
#include <sqlite3.h>
#include <iostream>

template <typename T>
SQLDataUpdater<T>::SQLDataUpdater(SQLDatabaseManager &manager)
    : db(manager.getHandle()) {}

template <typename T>
bool SQLDataUpdater<T>::updateData(const ITableKey<std::string> &key, const T &newValue)
{
    if (!key.isValid())
        return false;

    const std::string query = R"(
        UPDATE contacts SET
            full_name = ?,
            note = ?
        WHERE phone_number = ?
    )";

    sqlite3_stmt *stmt;
    if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
        return false;

    sqlite3_bind_text(stmt, 1, newValue.full_name.getValue().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, newValue.note.getValue().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, key.getKey().c_str(), -1, SQLITE_TRANSIENT);

    bool success = (sqlite3_step(stmt) == SQLITE_DONE);
    int rowsAffected = sqlite3_changes(db);
    sqlite3_finalize(stmt);

    return success || (rowsAffected > 0);
}

template class SQLDataUpdater<ContactData>;