#pragma once
#include "types.h"

class IDatabaseManager
{
public:
    virtual bool createDatabase(const cstr &dbName) = 0;
    virtual bool deleteDatabase(const cstr &dbName) = 0;
    virtual ~IDatabaseManager() = default;
};