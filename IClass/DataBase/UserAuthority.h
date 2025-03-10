#pragma once
#ifndef __user_authority__
#define __user_authority__
#include <utility>

enum class UserAuthority
{
    CREATE_DB,
    DELETE_DB,
    INSERT,
    DELETE_KEY,
    DELETE_VALUE,
    FIND_KEY,
    FIND_VALUE,
    max_size
};

template <typename __UserAuthority>
class UserAuthorityHandler
{
    using _ua = __UserAuthority;
    using mx = _ua::max_size;
    using _node = std::pair<_ua, bool>;

    _node *nodes;

public:
    UserAuthorityHandler() = default;
    virtual ~UserAuthorityHandler() = default;

    virtual void setAuthority(__UserAuthority type, bool value = false) = 0;
    bool getAuthority(__UserAuthority type) const;
};

#endif