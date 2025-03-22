#include "UserAuthorityChose.h"
#include <stdexcept>

UserAuthorityChose::UserAuthorityChose(int X, int Y, int W, int H, const char *L)
    : IUserAuthorityChose(X, Y, W, H, L)
{
    add("Administrator|Guest|Moderator");
    callback(authChangeCallback);
}

void UserAuthorityChose::connectAuthHandler(SQLUserAuthorityHandler *handler)
{
    if (!handler)
        throw std::invalid_argument("Handler cannot be null");
    authHandler = handler;

    value(0);
    authHandler->setAuthority(UserAuthority::FIND_KEY, true);
}

void UserAuthorityChose::authChangeCallback(Fl_Widget *w, void *data)
{
    auto chooser = static_cast<UserAuthorityChose *>(w);
    if (!chooser->authHandler)
        return;

    SQLUserAuthorityHandler::Role selectedRole;
    switch (chooser->value())
    {
    case 0:
        selectedRole = SQLUserAuthorityHandler::Role::Administrator;
        break;
    case 1:
        selectedRole = SQLUserAuthorityHandler::Role::Guest;
        break;
    case 2:
        selectedRole = SQLUserAuthorityHandler::Role::Moderator;
        break;
    default:
        return;
    }

    switch (selectedRole)
    {
    case SQLUserAuthorityHandler::Role::Administrator:
        for (size_t i = 0; i < static_cast<size_t>(UserAuthority::max_size); ++i)
        {
            chooser->authHandler->setAuthority(static_cast<UserAuthority>(i), true);
        }
        break;

    case SQLUserAuthorityHandler::Role::Guest:
        chooser->authHandler->setAuthority(UserAuthority::FIND_KEY, true);
        chooser->authHandler->setAuthority(UserAuthority::FIND_VALUE, true);
        break;

    case SQLUserAuthorityHandler::Role::Moderator:
        chooser->authHandler->setAuthority(UserAuthority::INSERT, true);
        chooser->authHandler->setAuthority(UserAuthority::DELETE_KEY, true);
        chooser->authHandler->setAuthority(UserAuthority::DELETE_VALUE, true);
        chooser->authHandler->setAuthority(UserAuthority::FIND_KEY, true);
        chooser->authHandler->setAuthority(UserAuthority::FIND_VALUE, true);
        break;
    }
}