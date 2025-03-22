#pragma once
#include "../../IClass/DataBase/DataDeleter.h"
#include "DataBaseManager.h"
#include "DataStruct.h"
#include <iostream>
#include <pqxx/pqxx>

template <typename T>
class SQLDataDelete : public IDataDelete<T>
{
    pqxx::connection &conn;

public:
    explicit SQLDataDelete(SQLDatabaseManager &manager);
    bool deleteByKey(const ITableKey<T> &key) override;
    bool deleteByField(const ITableField<T> &field) override;
};