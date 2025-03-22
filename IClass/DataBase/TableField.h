#ifndef __ITableField__
#define __ITableField__

template <typename T>
class ITableField
{
public:
    virtual T getValue() const = 0;
    virtual void setValue(const T &newValue) = 0;
    virtual ~ITableField() = default;
};

#endif