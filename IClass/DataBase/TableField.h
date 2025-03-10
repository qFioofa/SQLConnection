#pragma once
#include "types.h"

template <typename T>
class ITableField
{
public:
    virtual T getValue() const = 0;
    virtual void setValue(const T &newValue) = 0;
    virtual ~ITableField() = default;
};