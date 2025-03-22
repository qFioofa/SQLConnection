#include "GeneralInfoTab.h"
#include "../DataBase/TableCleaner.h"
#include <FL/Fl.H>
#include <string>

GeneralInfoTab::GeneralInfoTab(int X, int Y, int W, int H, IOutputTab *output, const char *L = nullptr)
    : IGeneralInfoTab(X, Y, W, H, L),
      manager(nullptr),
      outputTab(output)
{
    dbNameBox = new Fl_Box(10, 10, W - 20, 25, "Database: contacts.db");
    statusBox = new Fl_Box(10, 40, W - 20, 25, "Status: Ready");

    createDB = new Fl_Button(10, 70, 100, 30, "Create DB");
    deleteDB = new Fl_Button(120, 70, 100, 30, "Delete DB");
    truncateTableBtn = new Fl_Button(10, 110, 120, 30, "Truncate Table");
    resetTableBtn = new Fl_Button(140, 110, 120, 30, "Reset Table");

    createDB->callback(staticCreateCB, this);
    deleteDB->callback(staticDeleteCB, this);
    truncateTableBtn->callback(staticTruncateCB, this);
    resetTableBtn->callback(staticResetCB, this);

    end();
}

void GeneralInfoTab::setManager(IDatabaseManager *mgr)
{
    manager = dynamic_cast<SQLDatabaseManager *>(mgr);
}

void GeneralInfoTab::updateStatus(const std::string &message)
{
    statusBox->copy_label(("Status: " + message).c_str());

    if (outputTab)
    {
        bool success = message.find("failed") == std::string::npos;
        outputTab->appendOutput("General Info: " + message, success);
    }
    Fl::redraw();
}

void GeneralInfoTab::staticCreateCB(Fl_Widget *w, void *data)
{
    GeneralInfoTab *self = static_cast<GeneralInfoTab *>(data);
    self->onCreateDBCallback();
}

void GeneralInfoTab::staticDeleteCB(Fl_Widget *w, void *data)
{
    GeneralInfoTab *self = static_cast<GeneralInfoTab *>(data);
    self->onDeleteDBCallback();
}

void GeneralInfoTab::staticTruncateCB(Fl_Widget *w, void *data)
{
    GeneralInfoTab *self = static_cast<GeneralInfoTab *>(data);
    self->onTruncateCallback();
}

void GeneralInfoTab::staticResetCB(Fl_Widget *w, void *data)
{
    GeneralInfoTab *self = static_cast<GeneralInfoTab *>(data);
    self->onResetCallback();
}

void GeneralInfoTab::createDatabase()
{
    if (manager)
        onCreateDBCallback();
}

void GeneralInfoTab::deleteDatabase()
{
    if (manager)
        onDeleteDBCallback();
}

void GeneralInfoTab::truncateTable()
{
    if (manager)
        onTruncateCallback();
}

void GeneralInfoTab::resetTable()
{
    if (manager)
        onResetCallback();
}

void GeneralInfoTab::onCreateDBCallback()
{
    if (manager && outputTab)
    {
        bool success = manager->createDatabase(__DATABASE_NAME__);
        updateStatus(success ? "Database created" : "Creation failed");
    }
}

void GeneralInfoTab::onDeleteDBCallback()
{
    if (manager && outputTab)
    {
        bool success = manager->deleteDatabase("contacts.db");
        updateStatus(success ? "Database deleted" : "Deletion failed");
    }
}

void GeneralInfoTab::onTruncateCallback()
{
    if (manager && outputTab)
    {
        SQLTableCleaner cleaner(*manager, "contacts");
        bool success = cleaner.truncateTable();
        updateStatus(success ? "Table truncated" : "Truncation failed");
    }
}

void GeneralInfoTab::onResetCallback()
{
    if (manager && outputTab)
    {
        SQLTableCleaner cleaner(*manager, "contacts");
        bool success = cleaner.resetTable();
        updateStatus(success ? "Table reset" : "Reset failed");
    }
}

void GeneralInfoTab::deactivate()
{
    createDB->deactivate();
    deleteDB->deactivate();
    truncateTableBtn->deactivate();
    resetTableBtn->deactivate();
}
