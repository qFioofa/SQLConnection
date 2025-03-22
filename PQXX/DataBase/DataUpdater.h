#pragma once
#include "DataBaseManager.h"
#include "../../IClass/DataBase/DataUpdater.h"
#include "DataStruct.h"
#include "TableKey.h"
#include <pqxx/pqxx>
#include <iostream>

template <typename T>
class SQLDataUpdater : public IDataUpdater<T>
{
    pqxx::connection &conn;

public:
    explicit SQLDataUpdater(SQLDatabaseManager &manager);
    bool updateData(const ITableKey<std::string> &key, const T &newValue) override;
};