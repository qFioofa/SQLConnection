#pragma once
#include "../../IClass/DataBase/DataSearcher.h"
#include "DataBaseManager.h"
#include <iostream>
#include <pqxx/pqxx>

template <typename T>
class SQLDataSearcher : public IDataSearcher<T>
{
    pqxx::connection &conn;

public:
    explicit SQLDataSearcher(SQLDatabaseManager &manager)
        : conn(manager.getHandle()) {}

    std::vector<T> searchData(const T &filter) const override;
};