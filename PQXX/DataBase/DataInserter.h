#pragma once
#include "DataBaseManager.h"
#include "../../IClass/DataBase/DataInserter.h"
#include <iostream>
#include <pqxx/pqxx>

template <typename T>
class SQLDataInserter : public IDataInserter<T>
{
    pqxx::connection &conn;

public:
    explicit SQLDataInserter(SQLDatabaseManager &manager)
        : conn(manager.getHandle()) {}

    bool insertData(const T &data) override;
};