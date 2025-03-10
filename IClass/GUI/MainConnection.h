#pragma once
#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>

template <typename __IDatabaseManager>
class IMainConnection : public Fl_Group
{
protected:
    Fl_Input *hostInput;
    Fl_Input *portInput;
    Fl_Button *connectButton;
    __IDatabaseManager *dbManager;

public:
    IMainConnection(int X, int Y, int W, int H, const char *L = 0);
    virtual void connectManager(__IDatabaseManager *manager);
    virtual bool attemptConnection();
};