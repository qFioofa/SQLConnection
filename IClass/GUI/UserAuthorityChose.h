#pragma once
#include <FL/Fl_Choice.H>

template <typename UserAuthorityHandler, typename UserAuthority>
class IUserAuthorityChose : public Fl_Choice
{
protected:
    UserAuthorityHandler *authHandler;

public:
    IUserAuthorityChose(int X, int Y, int W, int H, const char *L = 0);
    virtual void connectAuthHandler(UserAuthorityHandler *handler);
    static void authChangeCallback(Fl_Widget *w, void *data);
};