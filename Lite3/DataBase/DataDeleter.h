#pragma once
#include "../../IClass/DataBase/DataDeleter.h"
#include "DataBaseManager.h"
#include "DataStruct.h"
#include <sqlite3.h>

template <typename T>
class SQLDataDelete : public IDataDelete<T>
{
    sqlite3 *db;

public:
    explicit SQLDataDelete(SQLDatabaseManager &manager);
    bool deleteByKey(const ITableKey<T> &key) override;
    bool deleteByField(const ITableField<T> &field) override;
};
