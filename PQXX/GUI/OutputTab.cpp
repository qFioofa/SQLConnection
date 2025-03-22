#include "OutputTab.h"

IOutputTab::IOutputTab(int X, int Y, int W, int H, const char *L)
    : Fl_Scroll(X, Y, W, H, L) {}

OutputTab::OutputTab(int X, int Y, int W, int H, const char *L)
    : IOutputTab(X, Y, W, H, L)
{
    textBuffer = new Fl_Text_Buffer();
    display = new Fl_Text_Display(10, 10, W - 20, H - 20);
    display->buffer(textBuffer);
    type(Fl_Scroll::VERTICAL_ALWAYS);
}

void OutputTab::appendOutput(const std::string &message, bool success)
{
    std::string formatted = getTimestamp() +
                            (success ? "[SUCCESS] " : "[ERROR] ") +
                            message + "\n";
    textBuffer->append(formatted.c_str());
    scroll_to_bottom();
}

void OutputTab::clearOutput()
{
    textBuffer->text("");
}

void OutputTab::scroll_to_bottom()
{
    int totalLines = textBuffer->count_lines(0, textBuffer->length());
    display->scroll(totalLines, 0);
    redraw();
}