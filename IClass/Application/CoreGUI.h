#pragma once
#include "../GUI/GUIInterface.h"
#include "../DataBase/Interfaces.h"

template <typename Role>
class ICoreGUI
{
public:
    virtual ~ICoreGUI() = default;

    virtual void initializeGUI() = 0;
    virtual void setUserRole(Role role) = 0;
    virtual void connectDatabase(const std::string &dbName) = 0;
    virtual void show() = 0;

protected:
    virtual void createMainWindow() = 0;
    virtual void setupTabs() = 0;
    virtual void applyPermissions() = 0;
};