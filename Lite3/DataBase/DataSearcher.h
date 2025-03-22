#pragma once
#include "../../IClass/DataBase/DataSearcher.h"
#include "DataBaseManager.h"

template <typename T>
class SQLDataSearcher : public IDataSearcher<T>
{
    sqlite3 *db;

public:
    explicit SQLDataSearcher(SQLDatabaseManager &manager)
        : db(manager.getHandle()) {}

    std::vector<T> searchData(const T &filter) const override;
};
