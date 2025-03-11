#pragma once
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Text_Display.H>
#include "types.h"

class IOutputTab : public Fl_Scroll
{
protected:
    Fl_Text_Buffer *textBuffer;
    Fl_Text_Display *display;

public:
    IOutputTab(int X, int Y, int W, int H, const char *L = 0);
    virtual void appendOutput(cstr message);
    virtual void clearOutput();
    void scroll_to_bottom();
};