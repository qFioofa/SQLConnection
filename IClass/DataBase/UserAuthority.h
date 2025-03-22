#pragma once
#ifndef __USER_AUTHORITY__
#define __USER_AUTHORITY__

#include <array>
#include <utility>
#include <stdio.h>

enum class UserAuthority
{
    CREATE_DB,
    DELETE_DB,
    INSERT,
    UPDATE,
    DELETE_KEY,
    DELETE_VALUE,
    FIND_KEY,
    FIND_VALUE,
    MAX_SIZE
};

template <typename UserAuthorityType>
class IUserAuthorityHandler
{
protected:
    using AuthorityNode = std::pair<UserAuthorityType, bool>;
    std::array<AuthorityNode, static_cast<size_t>(UserAuthorityType::MAX_SIZE)> nodes;

public:
    IUserAuthorityHandler()
    {
        for (size_t i = 0; i < nodes.size(); ++i)
        {
            nodes[i] = {static_cast<UserAuthorityType>(i), false};
        }
    }

    virtual ~IUserAuthorityHandler() = default;
    virtual void setAuthority(UserAuthorityType type, bool value)
    {
        nodes[static_cast<size_t>(type)].second = value;
    }

    virtual bool getAuthority(UserAuthorityType type) const
    {
        return nodes[static_cast<size_t>(type)].second;
    }
};

#endif