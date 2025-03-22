#pragma once
#include "../../IClass/GUI/OutputTab.h"

class OutputTab : public IOutputTab
{
public:
    OutputTab(int X, int Y, int W, int H, const char *L = nullptr);
    void appendOutput(const std::string &message, bool success) override;
    void clearOutput() override;
    void scroll_to_bottom() override;
};