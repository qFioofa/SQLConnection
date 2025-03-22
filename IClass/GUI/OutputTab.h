#pragma once
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Text_Display.H>
#include <string>
#include <chrono>
#include <iomanip>

class IOutputTab : public Fl_Scroll
{
protected:
    Fl_Text_Buffer *textBuffer;
    Fl_Text_Display *display;

    std::string getTimestamp()
    {
        auto now = std::chrono::system_clock::now();
        auto in_time = std::chrono::system_clock::to_time_t(now);
        std::stringstream ss;
        ss << std::put_time(std::localtime(&in_time), "[%Y-%m-%d %H:%M:%S] ");
        return ss.str();
    }

public:
    IOutputTab(int X, int Y, int W, int H, const char *L = 0);
    virtual void appendOutput(const std::string &message, bool success = true) = 0;
    virtual void clearOutput() = 0;
    virtual void scroll_to_bottom() = 0;
    virtual ~IOutputTab() = default;
};