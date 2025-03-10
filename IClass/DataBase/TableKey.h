#pragma once
#include "types.h"

template <typename T>
class ITableKey
{
public:
    virtual ~ITableKey() = default;

    virtual T getKey() const = 0;
    virtual void setKey(const T &newKey) = 0;

    virtual bool isValid() const = 0;
};