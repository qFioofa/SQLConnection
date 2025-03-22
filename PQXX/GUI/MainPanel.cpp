#include "MainPanel.h"

SQLMainPanel::SQLMainPanel(int X, int Y, int W, int H, const char *L)
    : MainPanel(X, Y, W, H, L)
{
    initializeComponents();
}

void SQLMainPanel::initializeComponents()
{
    connectionPanel = new MainConnection(0, 0, w(), 100);
    infoTab = new GeneralInfoTab(0, 100, w(), 80);
    authoritySelector = new UserAuthorityChose(0, 180, w(), 60);

    add(connectionPanel);
    add(infoTab);
    add(authoritySelector);

    refreshConnectionStatus(false);
}

void SQLMainPanel::refreshConnectionStatus(bool connected)
{
    infoTab->updateInfo();
    authoritySelector->activate();

    if (connected)
    {
        infoTab->statusBox->label("Connected");
        infoTab->statusBox->color(FL_GREEN);
    }
    else
    {
        infoTab->statusBox->label("Disconnected");
        infoTab->statusBox->color(FL_RED);
    }

    redraw();
}