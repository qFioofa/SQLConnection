#pragma once
#include <FL/Fl_Group.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include "../DataBase/DataBaseManager.h"
#include "OutputTab.h"

class IGeneralInfoTab : public Fl_Group
{
public:
    IGeneralInfoTab(int X, int Y, int W, int H, const char *L = nullptr) : Fl_Group(X, Y, W, H, L) {}
    virtual ~IGeneralInfoTab() = default;

    virtual void createDatabase() = 0;
    virtual void deleteDatabase() = 0;
    virtual void truncateTable() = 0;
    virtual void resetTable() = 0;
    virtual void updateStatus(const std::string &message) = 0;
    virtual void setManager(IDatabaseManager *mgr) = 0;
    virtual void deactivate() = 0;

protected:
    virtual void onCreateDBCallback() = 0;
    virtual void onDeleteDBCallback() = 0;
    virtual void onTruncateCallback() = 0;
    virtual void onResetCallback() = 0;
};