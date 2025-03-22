#ifndef __ITableCleaner__
#define __ITableCleaner__

class ITableCleaner
{
public:
    virtual bool truncateTable() = 0;
    virtual bool resetTable() = 0;
    virtual ~ITableCleaner() = default;
};

#endif