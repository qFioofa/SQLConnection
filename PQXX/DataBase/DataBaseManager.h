#ifndef __SQLDatabaseManager__
#define __SQLDatabaseManager__
#include "../../IClass/DataBase/DataBaseManager.h"
#include <pqxx/pqxx>
#include <string>
#include <iostream>
#include <memory>

#define __DATABASE_NAME__ "test_db"
#define __TABLE_NAME__ "contacts"

class SQLDatabaseManager : public IDatabaseManager
{
    std::unique_ptr<pqxx::connection> conn;
    std::string connection_string =
        "host=localhost port=5432 user=postgres password=secret";

public:
    SQLDatabaseManager() = default;
    ~SQLDatabaseManager() override = default;

    bool createDatabase(const std::string &dbName) override;
    bool deleteDatabase(const std::string &dbName) override;
    pqxx::connection &getHandle() { return *conn; }

    SQLDatabaseManager(const SQLDatabaseManager &) = delete;
    SQLDatabaseManager &operator=(const SQLDatabaseManager &) = delete;
};

#endif