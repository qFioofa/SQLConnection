#pragma once
#include <vector>
#include "types.h"

template <typename T>
class IDataSearcher
{
public:
    virtual std::vector<T> searchData(const T &filter) const = 0;
    virtual ~IDataSearcher() = default;
};