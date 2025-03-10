#pragma once
#include <FL/Fl_Group.H>
#include "MainConnection.h"
#include "GeneralInfoTab.h"
#include "UserAuthorityChose.h"

class MainPanel : public Fl_Group
{
protected:
    IMainConnection *connectionPanel;
    IGeneralInfoTab *infoTab;
    IUserAuthorityChose *authoritySelector;

public:
    MainPanel(int X, int Y, int W, int H, const char *L = 0);
    virtual ~MainPanel() = default;
    virtual void refreshConnectionStatus(bool connected);
};