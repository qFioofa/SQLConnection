#pragma once
#include "../../IClass/GUI/SearchTab.h"
#include "../DataBase/DataSearcher.h"
#include "../DataBase/DataStruct.h"
#include "OutputTab.h"
#include <FL/Fl_Choice.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>

template <typename T>
class SearchTab : public ISearchTab<T, SQLDataSearcher<T>>
{
private:
    Fl_Choice *searchType;
    Fl_Input *searchInput;
    Fl_Button *searchBtn;
    IOutputTab *outputTab;

public:
    SearchTab(int X, int Y, int W, int H, IOutputTab *output, const char *L = nullptr);
    void connectSearcher(SQLDataSearcher<T> *s) override;
    std::vector<T> performSearch() override;
    void deactivate() override;
    static void searchCallback(Fl_Widget *w, void *data);
};