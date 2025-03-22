#pragma once
#include "../../IClass/Application/CoreGUI.h"
#include "../GUI/GUIInterface.h"
#include <FL/Fl.H>
#include <FL/Fl_Pack.H>
#include <FL/Fl_Scroll.H>

class CoreGUI : public ICoreGUI<Role>
{
public:
    CoreGUI(int width, int height, const std::string &title);
    ~CoreGUI() override;

    void initializeGUI() override;
    void setUserRole(Role role) override;
    void connectDatabase(const std::string &dbName) override;
    void show() override;

protected:
    void createMainWindow() override;
    void setupTabs() override;
    void applyPermissions() override;

private:
    Fl_Window *mainWindow = nullptr;
    Fl_Scroll *globalScroll = nullptr;
    Fl_Pack *verticalPack = nullptr;
    SQLDatabaseManager dbManager;
    Role currentRole = Role::Guest;

    OutputTab *outputTab = nullptr;
    GeneralInfoTab *generalInfoTab = nullptr;
    InsertTab<ContactData> *insertTab = nullptr;
    DeleteTab *deleteTab = nullptr;
    SearchTab<ContactData> *searchTab = nullptr;
};