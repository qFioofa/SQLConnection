#pragma once
#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>

template <typename __IDataDeleter>
class IDeleteTab : public Fl_Group
{
protected:
    Fl_Input *deleteInput;
    __IDataDeleter *deleter;

public:
    IDeleteTab(int X, int Y, int W, int H, const char *L = 0);
    virtual void connectDeleter(__IDataDeleter *d);
    virtual bool executeDelete();
};