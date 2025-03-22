#pragma once
#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>

template <typename Deleter>
class IDeleteTab : public Fl_Group
{
protected:
    Deleter *deleter;

public:
    IDeleteTab(int X, int Y, int W, int H, const char *L = nullptr)
        : Fl_Group(X, Y, W, H, L), deleter(nullptr) {}
    virtual void connectDeleter(Deleter *d) = 0;
    virtual bool executeDelete() = 0;
    virtual ~IDeleteTab() = default;
    virtual void deactivate() = 0;
};