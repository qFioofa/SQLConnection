#pragma once
#include "CoreGUI.h"
#include "DataBase.h"
#include <memory>
#include <utility>
#include <FL/Fl.H>

template <
    typename TData,
    typename DatabaseManager,
    typename UserAuthorityHandler,
    typename UserAuthority,
    typename DataInserter,
    typename DataSearcher,
    typename DataUpdater,
    typename DataDeleter>
class IApplication
{
protected:
    std::unique_ptr<IDataBase<TData>> database;
    std::unique_ptr<ICoreGUI<
        DatabaseManager,
        UserAuthorityHandler,
        UserAuthority,
        TData,
        DataInserter,
        DataSearcher,
        DataUpdater,
        DataDeleter>>
        gui;

    void wireDependencies()
    {
        gui->connectDependencies(
            database->getDatabaseManager(),
            database->getAuthorityHandler(),
            database->getInserter(),
            database->getSearcher(),
            database->getUpdater(),
            database->getDeleter());
    }

public:
    IApplication(
        std::unique_ptr<DatabaseManager> dbManager,
        std::unique_ptr<DataInserter> inserter,
        std::unique_ptr<DataDeleter> deleter,
        std::unique_ptr<DataUpdater> updater,
        std::unique_ptr<DataSearcher> searcher)
        : database(std::make_unique<IDataBase<TData>>(
              std::move(dbManager),
              std::move(inserter),
              std::move(deleter),
              std::move(updater),
              std::move(searcher))),
          gui(std::make_unique<ICoreGUI<DatabaseManager, UserAuthorityHandler, UserAuthority, TData,
                                        DataInserter, DataSearcher, DataUpdater, DataDeleter>>())
    {
        wireDependencies();
    }

    virtual void initializeGUI(int X, int Y, int W, int H)
    {
        gui->initializeComponents(X, Y, W, H);
    }

    virtual void run()
    {
        gui->refreshUI();
        Fl::run();
    }

    virtual ~IApplication() = default;
};