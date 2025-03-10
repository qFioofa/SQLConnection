#pragma once
#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>

template <typename T, typename __IDataUpdater>
class IUpdateTab : public Fl_Group
{
protected:
    Fl_Input *keyInput;
    Fl_Input *newValueInput;
    __IDataUpdater<T> *updater;

public:
    IUpdateTab(int X, int Y, int W, int H, const char *L = 0);
    virtual void connectUpdater(__IDataUpdater<T> *u);
    virtual bool executeUpdate();
};