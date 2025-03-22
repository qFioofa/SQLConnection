#pragma once
#include "../../IClass/GUI/MainPanel.h"
#include "../DataBase/DataBaseManager.h"
#include "MainConnection.h"
#include "OutputTab.h"
#include <FL/Fl_Group.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>

class SQLMainPanel : public IMainPanel, public Fl_Group
{
private:
    SQLDatabaseManager *dbManager;
    OutputTab *infoTab;

    Fl_Button *createDbBtn;
    Fl_Button *deleteDbBtn;
    Fl_Input *keyInput;
    Fl_Input *nameInput;
    Fl_Input *noteInput;
    Fl_Button *updateBtn;

public:
    SQLMainPanel(int X, int Y, int W, int H, const char *L = nullptr);
    ~SQLMainPanel();

    bool createDatabase(const std::string &dbName) override;
    bool deleteDatabase(const std::string &dbName) override;
    bool updateTuple(const std::string &key, const std::string &newName, const std::string &newNote) override;

private:
    static void onCreateDbCallback(Fl_Widget *w, void *data);
    static void onDeleteDbCallback(Fl_Widget *w, void *data);
    static void onUpdateCallback(Fl_Widget *w, void *data);
};