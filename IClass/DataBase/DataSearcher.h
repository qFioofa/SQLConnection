#ifndef __IDataSearcher__
#define __IDataSearcher__
#include <vector>

template <typename T>
class IDataSearcher
{
public:
    virtual std::vector<T> searchData(const T &filter) const = 0;
    virtual ~IDataSearcher() = default;
};

#endif