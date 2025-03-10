#pragma once
#include <memory>
#include "../../IClass/DataBase/Interfaces.h"

template <typename T>
class IDataBase
{
protected:
    template <typename U>
    using uptr = std::unique_ptr<U>;

    uptr<IDatabaseManager> dbManager;
    uptr<IDataInserter<T>> dataInserter;
    uptr<IDataDeleter> dataDeleter;
    uptr<IDataUpdater<T>> dataUpdater;
    uptr<IDataSearcher<T>> dataSearcher;
    uptr<ITableCleaner> tableCleaner;
    uptr<IUserManager<UserAuthority, UserAuthorityHandler<UserAuthority>>> userManager;
    uptr<ITableKey<T>> tableKey;
    uptr<ITableField<T>> tableField;

public:
    virtual ~IDataBase() = default;

    explicit IDataBase(
        uptr<IDatabaseManager> dbMgr,
        uptr<IDataInserter<T>> inserter,
        uptr<IDataDeleter> deleter,
        uptr<IDataUpdater<T>> updater,
        uptr<IDataSearcher<T>> searcher,
        uptr<ITableCleaner> cleaner,
        uptr<IUserManager<UserAuthority, UserAuthorityHandler<UserAuthority>>> uMgr,
        uptr<ITableKey<T>> tKey,
        uptr<ITableField<T>> tField) : dbManager(std::move(dbMgr)),
                                       dataInserter(std::move(inserter)),
                                       dataDeleter(std::move(deleter)),
                                       dataUpdater(std::move(updater)),
                                       dataSearcher(std::move(searcher)),
                                       tableCleaner(std::move(cleaner)),
                                       userManager(std::move(uMgr)),
                                       tableKey(std::move(tKey)),
                                       tableField(std::move(tField))
    {
    }

    virtual bool initialize() = 0;
    virtual bool shutdown() = 0;
    virtual bool validateSchema() = 0;
};