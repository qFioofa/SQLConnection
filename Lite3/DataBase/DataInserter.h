#pragma once
#include "DataBaseManager.h"
#include "../../IClass/DataBase/DataInserter.h"

template <typename T>
class SQLDataInserter : public IDataInserter<T>
{
    sqlite3 *db;

public:
    explicit SQLDataInserter(SQLDatabaseManager &manager)
        : db(manager.getHandle()) {}

    bool insertData(const T &data) override;
};