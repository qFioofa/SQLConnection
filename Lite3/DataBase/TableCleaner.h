#pragma once
#include "../../IClass/DataBase/TableCleaner.h"
#include "DataBaseManager.h"

class SQLTableCleaner : public ITableCleaner
{
    sqlite3 *db;
    std::string tableName;

public:
    SQLTableCleaner(SQLDatabaseManager &manager, std::string table);

    bool truncateTable() override;
    bool resetTable() override;
};