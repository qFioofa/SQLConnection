#include "DeleteTab.h"
#include "../DataBase/TableKey.h"
#include "../DataBase/TableField.h"
#include "const.h"

DeleteTab::DeleteTab(int X, int Y, int W, int H, IOutputTab *output, const char *L)
    : IDeleteTab<SQLDataDelete<std::string>>(X, Y, W, H, L), outputTab(output)
{

    deleteType = new Fl_Choice(__DELETE_MARGIN__, Y + 10, W - 20, 25, "Delete By:");
    deleteType->add("Phone Number|Name|Note");
    deleteType->value(0);

    valueInput = new Fl_Input(__DELETE_MARGIN__, Y + 50, W - 20, 25, "Input:");

    deleteBtn = new Fl_Button(__LEFT_MARGIN__, Y + 90, W - 20, 25, "Delete Record");
    deleteBtn->callback(deleteCallback, this);
}

void DeleteTab::connectDeleter(SQLDataDelete<std::string> *d)
{
    deleter = d;
}

bool DeleteTab::executeDelete()
{
    std::string value = valueInput->value();
    if (value.empty())
    {
        outputTab->appendOutput("Error: No value provided!", false);
        return false;
    }

    bool success = false;
    std::stringstream msg;

    switch (deleteType->value())
    {
    case 0:
    {
        success = deleter->deleteByKey(SQLTableKey<std::string>(value));
        msg << "Delete by Phone: " << (success ? "Success" : "Failed");
        break;
    }
    case 1:
    {
        success = deleter->deleteByField(SQLTableField<std::string>(value));
        msg << "Delete by Name: " << (success ? "Success" : "Failed");
        break;
    }
    case 2:
    {
        success = deleter->deleteByField(SQLTableField<std::string>(value));
        msg << "Delete by Note: " << (success ? "Success" : "Failed");
        break;
    }
    }

    msg << ". Value: " << value;
    outputTab->appendOutput(msg.str(), success);
    return success;
}

void DeleteTab::deleteCallback(Fl_Widget *w, void *data)
{
    auto tab = static_cast<DeleteTab *>(data);
    tab->executeDelete();
}

void DeleteTab::deactivate()
{
    deleteType->deactivate();
    valueInput->deactivate();
    deleteBtn->deactivate();
}