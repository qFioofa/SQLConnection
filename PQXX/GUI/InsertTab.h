#pragma once
#include "../../IClass/GUI/InsertTab.h"
#include "../DataBase/DataInserter.h"
#include "../DataBase/DataStruct.h"
#include "OutputTab.h"
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>

template <typename T>
class InsertTab : public IInsertTab<T, SQLDataInserter<T>>
{
private:
    Fl_Input *phoneInput;
    Fl_Input *nameInput;
    Fl_Input *noteInput;
    Fl_Button *insertBtn;
    IOutputTab *outputTab;

public:
    InsertTab(int X, int Y, int W, int H, IOutputTab *output, const char *L = nullptr);
    void connectInserter(SQLDataInserter<T> *ins) override;
    bool executeInsert() override;
    void deactivate() override;
    static void insertCallback(Fl_Widget *w, void *data);
};