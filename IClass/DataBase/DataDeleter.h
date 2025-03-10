#pragma once
#include "types.h"

class IDataDeleter
{
public:
    virtual void deleteByKey() = 0;
    virtual void deleteByField() = 0;
    virtual ~IDataDeleter() = default;
};