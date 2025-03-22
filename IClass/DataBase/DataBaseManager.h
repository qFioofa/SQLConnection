#ifndef __IDatabaseManager__
#define __IDatabaseManager__

#include <string>

class IDatabaseManager
{
public:
    virtual ~IDatabaseManager() = default;
    virtual bool createDatabase(const std::string &dbName) = 0;
    virtual bool deleteDatabase(const std::string &dbName) = 0;
};

#endif