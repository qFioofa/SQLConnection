#include "DataDeleter.h"
#include <sqlite3.h>
#ifdef __IDataDelete__

template <typename T>
SQLDataDelete<T>::SQLDataDelete(SQLDatabaseManager &manager) : db(manager.getHandle()) {}

template <typename T>
bool SQLDataDelete<T>::deleteByKey(const ITableKey<T> &key)
{
    if (!key.isValid())
    {
        return false;
    }

    const std::string query = "DELETE FROM contacts WHERE phone_number = ?";
    sqlite3_stmt *stmt;
    if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
    {
        return false;
    }

    sqlite3_bind_text(stmt, 1, key.getKey().c_str(), -1, SQLITE_TRANSIENT);
    if (sqlite3_step(stmt) != SQLITE_DONE)
    {
        sqlite3_finalize(stmt);
        return false;
    }

    int rowsAffected = sqlite3_changes(db);
    sqlite3_finalize(stmt);

    return rowsAffected > 0;
}

template <typename T>
bool SQLDataDelete<T>::deleteByField(const ITableField<T> &field)
{
    if (field.getValue().empty())
    {
        return false;
    }

    const std::string query = "DELETE FROM contacts WHERE full_name = ? OR note = ?";
    sqlite3_stmt *stmt;
    if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
    {
        return false;
    }

    sqlite3_bind_text(stmt, 1, field.getValue().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, field.getValue().c_str(), -1, SQLITE_TRANSIENT);
    if (sqlite3_step(stmt) != SQLITE_DONE)
    {
        sqlite3_finalize(stmt);
        return false;
    }

    int rowsAffected = sqlite3_changes(db);
    sqlite3_finalize(stmt);

    return rowsAffected > 0;
}

template class SQLDataDelete<std::string>;

#endif