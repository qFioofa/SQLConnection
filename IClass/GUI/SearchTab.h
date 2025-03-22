#pragma once
#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <vector>

template <typename T, typename IDataSearcher>
class ISearchTab : public Fl_Group
{
protected:
    Fl_Input *searchInput;
    Fl_Button *searchButton;
    IDataSearcher *searcher;

public:
    ISearchTab(int X, int Y, int W, int H, const char *L = nullptr)
        : Fl_Group(X, Y, W, H, L),
          searchInput(nullptr),
          searchButton(nullptr),
          searcher(nullptr) {}
    virtual void connectSearcher(IDataSearcher *s) = 0;
    virtual std::vector<T> performSearch() = 0;
    virtual void deactivate() = 0;
};