#pragma once
#include <FL/Fl_Group.H>
#include "../../IClass/GUI/GUIInterface.h"
#define sqlc_width 800
#define sqlc_hight 600

template <typename __IDatabaseManager, 
          typename __UserAuthorityHandler,
          typename __UserAuthority,
          typename __IDataInserter,
          typename __IDataSearcher,
          typename __IDataUpdater,
          typename __IDataDeleter>
class ICoreGUI : public Fl_Group {
protected:
    MainPanel<__IDatabaseManager, __UserAuthorityHandler, __UserAuthority>* mainPanel;
    IInsertTab<__UserAuthority, __IDataInserter>* insertTab;
    ISearchTab<__UserAuthority, __IDataSearcher>* searchTab;
    IUpdateTab<__UserAuthority, __IDataUpdater>* updateTab;
    IDeleteTab<__IDataDeleter>* deleteTab;
    IOutputTab* outputTab;

    __IDatabaseManager* dbManager;
    __UserAuthorityHandler* authHandler;
    
    virtual void initializeComponents() {
        mainPanel = new MainPanel<__IDatabaseManager, __UserAuthorityHandler, __UserAuthority>(0, 0, sqlc_width, sqlc_hight);
        insertTab = new IInsertTab<__UserAuthority, __IDataInserter>(0, 0, sqlc_width, sqlc_hight);
        searchTab = new ISearchTab<__UserAuthority, __IDataSearcher>(0, 0, sqlc_width, sqlc_hight);
        updateTab = new IUpdateTab<__UserAuthority, __IDataUpdater>(0, 0, sqlc_width, sqlc_hight);
        deleteTab = new IDeleteTab<__IDataDeleter>(0, 0, sqlc_width, sqlc_hight);
        outputTab = new IOutputTab(0, 0, sqlc_width, sqlc_hight);

        connectDatabaseManager(dbManager);
        connectAuthorityHandler(authHandler);
    }

public:
    ICoreGUI(int X, int Y, int W, int H, const char* L = 0)
        : Fl_Group(X, Y, W, H, L) {
        initializeComponents();
    }

    virtual void connectDatabaseManager(__IDatabaseManager* manager) {
        dbManager = manager;
        mainPanel->connectionPanel->connectManager(manager);
        mainPanel->infoTab->connectManager(manager);
    }

    virtual void connectAuthorityHandler(__UserAuthorityHandler* handler) {
        authHandler = handler;
        mainPanel->authoritySelector->connectAuthHandler(handler);
        insertTab->connectInserter(handler->getInserter());
        searchTab->connectSearcher(handler->getSearcher());
        updateTab->connectUpdater(handler->getUpdater());
        deleteTab->connectDeleter(handler->getDeleter());
    }

    virtual void refreshUI() {
        mainPanel->refreshConnectionStatus(dbManager->isConnected());
        mainPanel->infoTab->updateInfo();
        outputTab->clearOutput();
    }

    virtual void handleLayout() {
        mainPanel->size(W(), H());
        outputTab->resize(0, H()-200, W(), 200);
    }

    virtual ~ICoreGUI() {
        delete mainPanel;
        delete insertTab;
        delete searchTab;
        delete updateTab;
        delete deleteTab;
        delete outputTab;
    }
};