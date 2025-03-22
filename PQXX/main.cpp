#include "./Application/CoreGUI.h"
#include "./GUI/MainConnection.h"
#include <FL/Fl.H>

int main(int argc, char **argv)
{
    MainConnection roleWindow(300, 150, "User Role");
    roleWindow.show();
    while (roleWindow.shown())
        Fl::wait();

    CoreGUI app(700, 700, "Database Manager");
    app.setUserRole(roleWindow.getSelectedRole());
    app.connectDatabase("contacts.db");
    app.initializeGUI();
    app.show();

    return Fl::run();
}