#pragma once
#include "../../IClass/DataBase/TableKey.h"
#include <string>

template <typename T>
class SQLTableKey : public ITableKey<T>
{
    T key;

public:
    SQLTableKey() = default;
    explicit SQLTableKey(T key) : key(key) {}

    T getKey() const override { return key; }
    void setKey(const T &newKey) override { key = newKey; }
    bool isValid() const override { return !key.empty(); }
};
