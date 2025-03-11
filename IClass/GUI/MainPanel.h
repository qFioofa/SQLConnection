#pragma once
#include <FL/Fl_Group.H>
#include "MainConnection.h"
#include "GeneralInfoTab.h"
#include "UserAuthorityChose.h"

template <typename __IDatabaseManage, typename __UserAuthorityHandler, typename __UserAuthority>
class MainPanel : public Fl_Group
{
protected:
    IMainConnection<__IDatabaseManage> *connectionPanel;
    IGeneralInfoTab<__IDatabaseManage> *infoTab;
    IUserAuthorityChose<__UserAuthorityHandler, __UserAuthority> *authoritySelector;

public:
    MainPanel(int X, int Y, int W, int H, const char *L = 0);
    virtual ~MainPanel() = default;
    virtual void refreshConnectionStatus(bool connected);
};