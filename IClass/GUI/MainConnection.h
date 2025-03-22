#pragma once
#include <FL/Fl_Window.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Button.H>
#include "../DataBase/UserAuthority.h"

template <typename Role>
class IMainConnection : public Fl_Window
{
public:
    IMainConnection(int width, int height, const char *title) : Fl_Window(width, height, title), roleChoice(nullptr), confirmButton(nullptr) {}
    virtual ~IMainConnection() = default;

    virtual Role getSelectedRole() const
    {
        return selectedRole;
    }

protected:
    Fl_Choice *roleChoice;
    Fl_Button *confirmButton;
    Role selectedRole;

    static void confirmCallback(Fl_Widget *widget, void *data)
    {
        IMainConnection<Role> *window = static_cast<IMainConnection<Role> *>(data);
        window->selectedRole = static_cast<Role>(window->roleChoice->value());
        window->hide();
    }
};