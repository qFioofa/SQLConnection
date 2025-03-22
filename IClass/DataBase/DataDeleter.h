#ifndef __IDataDelete__
#define __IDataDelete__
#include "TableKey.h"
#include "TableField.h"

template <typename T>
class IDataDelete
{
public:
    virtual ~IDataDelete() = default;
    virtual bool deleteByKey(const ITableKey<T> &key) = 0;
    virtual bool deleteByField(const ITableField<T> &field) = 0;
};

#endif