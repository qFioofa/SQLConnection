#pragma once
#include "../DataBase/DataDeleter.h"
#include "../../IClass/GUI/DeleteTab.h"
#include "OutputTab.h"
#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Choice.H>

class DeleteTab : public IDeleteTab<SQLDataDelete<std::string>>
{
private:
    Fl_Choice *deleteType;
    Fl_Input *valueInput;
    Fl_Button *deleteBtn;
    IOutputTab *outputTab;

public:
    DeleteTab(int X, int Y, int W, int H, IOutputTab *output, const char *L = nullptr);
    void connectDeleter(SQLDataDelete<std::string> *d) override;
    bool executeDelete() override;
    void deactivate() override;
    static void deleteCallback(Fl_Widget *w, void *data);
};