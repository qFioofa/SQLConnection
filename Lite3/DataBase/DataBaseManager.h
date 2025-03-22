#ifndef __SQLDatabaseManager__
#define __SQLDatabaseManager__
#include "../../IClass/DataBase/DataBaseManager.h"
#include <sqlite3.h>
#include <string>
#define __DATABASE_NAME__ "test.db"
#define __TABLE_NAME__ "contacts"

class SQLDatabaseManager : public IDatabaseManager
{
    sqlite3 *db = nullptr;

public:
    SQLDatabaseManager() = default;
    ~SQLDatabaseManager() override;

    bool createDatabase(const std::string &dbName) override;
    bool deleteDatabase(const std::string &dbName) override;
    sqlite3 *getHandle() const { return db; }

    SQLDatabaseManager(const SQLDatabaseManager &) = delete;
    SQLDatabaseManager &operator=(const SQLDatabaseManager &) = delete;
};

#endif