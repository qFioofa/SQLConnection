#pragma once
#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>

template <typename T, typename __IDataSearcher>
class ISearchTab : public Fl_Group
{
protected:
    Fl_Input *searchInput;
    Fl_Button *searchButton;
    __IDataSearcher<T> *searcher;

public:
    ISearchTab(int X, int Y, int W, int H, const char *L = 0);
    virtual void connectSearcher(__IDataSearcher<T> *s);
    virtual std::vector<T> performSearch();
};