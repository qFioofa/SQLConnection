#pragma once

template <typename T>
class IDataInserter
{
public:
    virtual bool insertData(const T &data) = 0;
    virtual ~IDataInserter() = default;
};