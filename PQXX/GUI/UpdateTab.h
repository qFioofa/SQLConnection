#pragma once
#include "../../IClass/GUI/UpdateTab.h"
#include "../DataBase/DataUpdater.h"
#include "../DataBase/DataStruct.h"
#include "OutputTab.h"
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>

template <typename T>
class UpdaterTab : public IUpdateTab<T, SQLDataUpdater<T>>
{
private:
    Fl_Input *keyInput;
    Fl_Input *nameInput;
    Fl_Input *noteInput;
    Fl_Button *updateBtn;
    IOutputTab *outputTab;

public:
    UpdaterTab(int X, int Y, int W, int H, IOutputTab *output, const char *L = nullptr);
    void connectUpdater(SQLDataUpdater<T> *upd) override;
    bool executeUpdate() override;
    void deactivate() override;
    static void updateCallback(Fl_Widget *w, void *data);
};