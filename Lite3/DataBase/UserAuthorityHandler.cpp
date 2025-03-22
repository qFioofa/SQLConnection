#include "UserAuthorityHandler.h"

SQLUserAuthorityHandler::SQLUserAuthorityHandler(Role role)
{
    setRolesAuthority(role);
}

void SQLUserAuthorityHandler::setRolesAuthority(Role role)
{
    for (int i = 0; i < nodes.size(); ++i)
    {
        nodes[i].second = false;
    }

    switch (role)
    {
    case Role::Administrator:
        for (auto &node : nodes)
        {
            node.second = true;
        }
        break;

    case Role::Guest:
        setAuthority(UserAuthority::FIND_KEY, true);
        setAuthority(UserAuthority::FIND_VALUE, true);
        break;

    case Role::Moderator:
        setAuthority(UserAuthority::INSERT, true);
        setAuthority(UserAuthority::UPDATE, true);
        setAuthority(UserAuthority::DELETE_KEY, true);
        setAuthority(UserAuthority::DELETE_VALUE, true);
        setAuthority(UserAuthority::FIND_KEY, true);
        setAuthority(UserAuthority::FIND_VALUE, true);
        break;
    }
}

void SQLUserAuthorityHandler::setRole(Role role)
{
    setRolesAuthority(role);
}

void SQLUserAuthorityHandler::setAuthority(UserAuthority type, bool value)
{
    IUserAuthorityHandler::setAuthority(type, value);
}

bool SQLUserAuthorityHandler::getAuthority(UserAuthority type) const
{
    return IUserAuthorityHandler::getAuthority(type);
}