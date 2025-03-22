#include "DataInserter.h"
#include "DataStruct.h"

template <typename T>
bool SQLDataInserter<T>::insertData(const T &data)
{
    const auto [query, params] = data.toInsert();
    sqlite3_stmt *stmt;

    if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
        return false;

    for (size_t i = 0; i < params.size(); ++i)
    {
        sqlite3_bind_text(stmt, i + 1, params[i].c_str(), -1, SQLITE_TRANSIENT);
    }

    const bool success = sqlite3_step(stmt) == SQLITE_DONE;
    sqlite3_finalize(stmt);
    return success;
}

template class SQLDataInserter<ContactData>;