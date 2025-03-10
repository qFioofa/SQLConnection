#pragma once
#include <FL/Fl_Group.H>
#include <FL/Fl_Box.H>

template <typename __IDatabaseManager>
class IGeneralInfoTab : public Fl_Group
{
protected:
    Fl_Box *dbNameBox;
    Fl_Box *statusBox;
    __IDatabaseManager *dbManager;

public:
    IGeneralInfoTab(int X, int Y, int W, int H, const char *L = 0);
    virtual void connectManager(__IDatabaseManager *manager);
    virtual void updateInfo();
};