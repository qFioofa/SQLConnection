#include "MainConnection.h"

MainConnection::MainConnection(int width, int height, const char *title)
    : IMainConnection(width, height, title), selectedRole(Role::Guest)
{
    roleChoice = new Fl_Choice(width / 2 - 75, height / 2 - 40, 200, 30, "Authority:");
    roleChoice->add("Guest|Moderator|Admin");
    roleChoice->value(0);

    confirmButton = new Fl_Button(width / 2 - 50, height / 2 + 10, 100, 30, "Enter");
    confirmButton->callback(confirmCallback, this);

    end();
}

Role MainConnection::getSelectedRole() const
{
    return selectedRole;
}

void MainConnection::confirmCallback(Fl_Widget *widget, void *data)
{
    MainConnection *window = static_cast<MainConnection *>(data);
    window->selectedRole = static_cast<Role>(window->roleChoice->value());
    window->hide();
}