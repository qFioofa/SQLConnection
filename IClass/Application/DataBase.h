#pragma once
#include <memory>
#include "../DataBase/Interfaces.h"

template <typename TData>
class IDataBase
{
protected:
    IUserAuthorityHandler *authorityHandler;
    IDatabaseManager *manager;
    IDataInserter<TData> *inserter;
    IDataSearcher<TData> *searcher;
    IDataUpdater<TData> *updater;
    IDataDelete<TData> *deleter;
    ITableCleaner *cleaner;

public:
    virtual ~IDataBase() = default;
};
