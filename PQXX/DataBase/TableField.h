#pragma once
#include "../../IClass/DataBase/TableField.h"
#include <string>

template <typename T>
class SQLTableField : public ITableField<T>
{
    T value;

public:
    SQLTableField() = default;
    explicit SQLTableField(T value) : value(value) {}

    T getValue() const override { return value; }
    void setValue(const T &newValue) override { value = newValue; }
};
