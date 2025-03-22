#ifndef __IDataUpdater__
#define __IDataUpdater__
#include <string>
#include "TableKey.h"

template <typename T>
class IDataUpdater
{
public:
    virtual ~IDataUpdater() = default;
    virtual bool updateData(const ITableKey<std::string> &key, const T &newValue) = 0;
};

#endif