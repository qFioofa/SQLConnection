#pragma once
#include "../../IClass/DataBase/TableCleaner.h"
#include "DataBaseManager.h"
#include <iostream>
#include <pqxx/pqxx>
#include <string>

class SQLTableCleaner : public ITableCleaner
{
    pqxx::connection &conn;
    std::string tableName;
    std::string tableSchema;

public:
    SQLTableCleaner(SQLDatabaseManager &manager, const std::string &table);

    bool truncateTable() override;
    bool resetTable() override;

private:
    bool fetchTableSchema();
};