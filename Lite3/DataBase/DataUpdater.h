#pragma once
#include "DataBaseManager.h"
#include "../../IClass/DataBase/DataUpdater.h"
#include "DataBaseManager.h"
#include "DataStruct.h"
#include "TableKey.h"

template <typename T>
class SQLDataUpdater
{
    sqlite3 *db;

public:
    explicit SQLDataUpdater(SQLDatabaseManager &manager);
    bool updateData(const ITableKey<std::string> &key, const T &newValue);
};