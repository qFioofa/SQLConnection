#pragma once
#include <FL/Fl_Choice.H>

template <typename __UserAuthorityHandler, typename __UserAuthority>
class IUserAuthorityChose : public Fl_Choice
{
protected:
    __UserAuthorityHandler<UserAuthority> *authHandler;

public:
    IUserAuthorityChose(int X, int Y, int W, int H, const char *L = 0);
    virtual void connectAuthHandler(__UserAuthorityHandler<__UserAuthority> *handler);
    static void authChangeCallback(Fl_Widget *w, void *data);
};