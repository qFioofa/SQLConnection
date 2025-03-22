#include "CoreGUI.h"

CoreGUI::CoreGUI(int width, int height, const std::string &title)
{
    createMainWindow();
}

CoreGUI::~CoreGUI()
{
    delete searchTab;
    delete deleteTab;
    delete insertTab;
    delete generalInfoTab;
    delete outputTab;
    delete verticalPack;
    delete globalScroll;
    delete mainWindow;
}

void CoreGUI::initializeGUI()
{
    setupTabs();
    applyPermissions();
}

void CoreGUI::setUserRole(Role role)
{
    currentRole = role;
    applyPermissions();
}

void CoreGUI::connectDatabase(const std::string &dbName)
{
    if (dbManager.createDatabase(dbName))
    {
        if (generalInfoTab)
        {
            generalInfoTab->updateStatus("Connected to " + dbName);
        }
    }
};

void CoreGUI::show()
{
    if (mainWindow)
    {
        mainWindow->end();
        mainWindow->show();
    }
}

void CoreGUI::createMainWindow()
{
    mainWindow = new Fl_Window(700, 700, "Database GUI");
    globalScroll = new Fl_Scroll(0, 0, 700, 700);
    globalScroll->type(Fl_Scroll::VERTICAL_ALWAYS | Fl_Scroll::HORIZONTAL_ALWAYS);

    verticalPack = new Fl_Pack(0, 0, 700, 700);
    verticalPack->type(Fl_Pack::VERTICAL);
    verticalPack->spacing(25);
}

void CoreGUI::setupTabs()
{
    outputTab = new OutputTab(0, 0, 700, 240, "Operation Log");

    generalInfoTab = new GeneralInfoTab(0, 0, 600, 150, outputTab, "Database Controls");
    generalInfoTab->setManager(&dbManager);
    verticalPack->add(generalInfoTab);

    insertTab = new InsertTab<ContactData>(0, 0, 600, 180, outputTab, "Insert");
    verticalPack->add(insertTab);

    deleteTab = new DeleteTab(0, 0, 580, 150, outputTab, "Delete");
    verticalPack->add(deleteTab);

    searchTab = new SearchTab<ContactData>(0, 330, 580, 150, outputTab, "Search");
    verticalPack->add(searchTab);

    verticalPack->add(outputTab);
}

void CoreGUI::applyPermissions()
{

    switch (currentRole)
    {
    case Role::Administrator:
        if (generalInfoTab)
            generalInfoTab->deactivate();
        break;
    case Role::Moderator:
        break;
    case Role::Guest:
        if (generalInfoTab)
            generalInfoTab->deactivate();
        if (insertTab)
            insertTab->deactivate();
        if (deleteTab)
            deleteTab->deactivate();
        break;
    default:
        break;
    }

    if (mainWindow)
        mainWindow->redraw();
}