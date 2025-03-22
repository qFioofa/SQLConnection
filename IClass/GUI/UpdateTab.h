#pragma once
#include <FL/Fl_Group.H>

template <typename T, typename Updater>
class IUpdateTab : public Fl_Group
{
protected:
    Updater *updater;

public:
    IUpdateTab(int X, int Y, int W, int H, const char *L = nullptr)
        : Fl_Group(X, Y, W, H, L), updater(nullptr) {}

    virtual void connectUpdater(Updater *upd) = 0;
    virtual bool executeUpdate() = 0;
    virtual void deactivate() = 0;
};