#pragma once
#include "../DataBase/UserAuthorityHandler.h"
#include "../../IClass/GUI/UserAuthorityChose.h"
#include <FL/Fl_Choice.H>

class UserAuthorityChose : public IUserAuthorityChose<SQLUserAuthorityHandler, UserAuthority>
{
public:
    UserAuthorityChose(int X, int Y, int W, int H, const char *L = nullptr);
    void connectAuthHandler(SQLUserAuthorityHandler *handler);
    static void authChangeCallback(Fl_Widget *w, void *data);
};