#pragma once
#include "types.h"

template <typename T>
class IDataUpdater
{
public:
    virtual void updateData(const T &filter, const T &newValue) = 0;
    virtual ~IDataUpdater() = default;
};