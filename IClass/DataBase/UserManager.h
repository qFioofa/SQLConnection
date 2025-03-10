#pragma once
#include "UserAuthority.h"
#include "types.h"

template <typename T, typename U>
class IUserManager
{
public:
    virtual void addUser(const T &user) = 0;
    virtual void removeUser(const T &user) = 0;
    virtual U getAuthorityHandler(const T &user) const = 0;
    virtual ~IUserManager() = default;
};