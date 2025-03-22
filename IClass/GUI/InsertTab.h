#pragma once
#include <FL/Fl_Group.H>

template <typename T, typename Inserter>
class IInsertTab : public Fl_Group
{
protected:
    Inserter *inserter;

public:
    IInsertTab(int X, int Y, int W, int H, const char *L = nullptr)
        : Fl_Group(X, Y, W, H, L), inserter(nullptr) {}

    virtual void connectInserter(Inserter *ins) = 0;
    virtual bool executeInsert() = 0;
    virtual void deactivate() = 0;
};