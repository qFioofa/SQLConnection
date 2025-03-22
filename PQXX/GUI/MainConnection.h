#pragma once
#include "../../IClass/GUI/MainConnection.h"
#include "../DataBase/UserAuthorityHandler.h"

class MainConnection : public IMainConnection<Role>
{
public:
    MainConnection(int width, int height, const char *title);
    Role getSelectedRole() const override;

private:
    Fl_Choice *roleChoice;
    Fl_Button *confirmButton;
    Role selectedRole;

    static void confirmCallback(Fl_Widget *widget, void *data);
};