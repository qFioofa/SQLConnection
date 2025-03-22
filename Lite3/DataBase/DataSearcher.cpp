#include "DataSearcher.h"
#include "DataStruct.h"

template <typename T>
std::vector<T> SQLDataSearcher<T>::searchData(const T &filter) const
{
    std::vector<T> results;
    const auto [query, params] = filter.toSearch();

    sqlite3_stmt *stmt;
    if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
        return results;

    for (size_t i = 0; i < params.size(); ++i)
    {
        sqlite3_bind_text(stmt, i + 1, params[i].c_str(), -1, SQLITE_TRANSIENT);
    }

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        results.push_back(T::fromSQL(stmt));
    }

    sqlite3_finalize(stmt);
    return results;
}

template class SQLDataSearcher<ContactData>;