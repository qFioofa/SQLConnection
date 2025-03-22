#ifndef __IDataInserter__
#define __IDataInserter__

template <typename T>
class IDataInserter
{
public:
    virtual bool insertData(const T &data) = 0;
    virtual ~IDataInserter() = default;
};

#endif