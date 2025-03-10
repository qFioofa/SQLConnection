#pragma once
#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>

template <typename T, typename __IDataInserter>
class IInsertTab : public Fl_Group
{
protected:
    Fl_Input *dataInput;
    __IDataInserter<T> *inserter;

public:
    IInsertTab(int X, int Y, int W, int H, const char *L = 0);
    virtual void connectInserter(__IDataInserter<T> *ins);
    virtual bool executeInsert();
};