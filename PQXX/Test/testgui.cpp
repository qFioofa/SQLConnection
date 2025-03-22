#include <FL/Fl_Pack.H>
#include <FL/Fl_Window.H>
#include <FL/Fl.H>
#include <iostream>
#include "MainConnection.h"
#include "InsertTab.h"
#include "UpdateTab.h"
#include "DeleteTab.h"
#include "OutputTab.h"
#include "SearchTab.h"
#include "GeneralInfoTab.h"

int main()
{
    MainConnection roleWindow(300, 150, "User Authority");
    roleWindow.show();
    while (roleWindow.shown())
        Fl::wait();

    Fl_Window win(700, 700, "Database GUI");
    Fl_Scroll *globalScroll = new Fl_Scroll(0, 0, 700, 700);
    globalScroll->type(Fl_Scroll::VERTICAL_ALWAYS | Fl_Scroll::HORIZONTAL_ALWAYS);

    SQLDatabaseManager manager;
    manager.createDatabase(__DATABASE_NAME__);

    Fl_Pack *verticalPack = new Fl_Pack(0, 0, 700, 700);
    verticalPack->type(Fl_Pack::VERTICAL);
    verticalPack->spacing(25);

    OutputTab *outputTab = new OutputTab(0, 0, 700, 240, "Operation Log");

    GeneralInfoTab *generalInfoTab = new GeneralInfoTab(
        0, 0, 600, 150, outputTab, "Database Controls");
    generalInfoTab->setManager(&manager);
    verticalPack->add(generalInfoTab);

    InsertTab<ContactData> *insertTab = new InsertTab<ContactData>(
        0, 0, 600, 180, outputTab, "Insert");
    SQLDataInserter<ContactData> inserter(manager);
    insertTab->connectInserter(&inserter);
    verticalPack->add(insertTab);

    DeleteTab *deleteTab = new DeleteTab(0, 0, 580, 150, outputTab, "Delete");
    SQLDataDelete<std::string> deleter(manager);
    deleteTab->connectDeleter(&deleter);
    verticalPack->add(deleteTab);

    SearchTab<ContactData> *searchTab = new SearchTab<ContactData>(
        0, 330, 580, 150, outputTab, "Search");
    SQLDataSearcher<ContactData> searcher(manager);
    searchTab->connectSearcher(&searcher);
    verticalPack->add(searchTab);

    UpdaterTab<ContactData> *updateTab = new UpdaterTab<ContactData>(
        0, 0, 600, 180, outputTab, "Update");
    SQLDataUpdater<ContactData> updater(manager);
    updateTab->connectUpdater(&updater);
    verticalPack->add(updateTab);

    switch (roleWindow.getSelectedRole())
    {
    case Role::Guest:
        generalInfoTab->deactivate();
        insertTab->deactivate();
        deleteTab->deactivate();
        updateTab->deactivate();
        break;
    case Role::Administrator:
        break;
    case Role::Moderator:;
        insertTab->deactivate();
        deleteTab->deactivate();
        updateTab->deactivate();
        break;
    }

    verticalPack->add(outputTab);
    verticalPack->end();

    win.resizable(verticalPack);
    win.redraw();
    win.show();
    return Fl::run();
}