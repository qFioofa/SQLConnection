#pragma once
#include "../../IClass/DataBase/UserAuthority.h"

enum class Role
{
    Guest,
    Administrator,
    Moderator
};

class SQLUserAuthorityHandler : public IUserAuthorityHandler<UserAuthority>
{
    void setRolesAuthority(Role role);

public:
    explicit SQLUserAuthorityHandler(Role role);
    ~SQLUserAuthorityHandler() override = default;

    void setRole(Role role);
    void setAuthority(UserAuthority type, bool value = false) override;
    bool getAuthority(UserAuthority type) const override;
};