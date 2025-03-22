#pragma once
#include "../DataBase/DataBaseManager.h"
#include "../../IClass/GUI/GeneralInfoTab.h"
#include "OutputTab.h"
#include <FL/Fl_Group.H>
#include <FL/Fl_Box.H>

class GeneralInfoTab : public IGeneralInfoTab
{
public:
    GeneralInfoTab(int X, int Y, int W, int H, IOutputTab *output, const char *L);
    ~GeneralInfoTab() override = default;

    void createDatabase() override;
    void deleteDatabase() override;
    void truncateTable() override;
    void resetTable() override;
    void updateStatus(const std::string &message) override;
    void setManager(IDatabaseManager *mgr) override;
    void deactivate() override;

protected:
    void onCreateDBCallback() override;
    void onDeleteDBCallback() override;
    void onTruncateCallback() override;
    void onResetCallback() override;

private:
    SQLDatabaseManager *manager;
    IOutputTab *outputTab;

    Fl_Box *dbNameBox;
    Fl_Box *statusBox;
    Fl_Button *createDB;
    Fl_Button *deleteDB;
    Fl_Button *truncateTableBtn;
    Fl_Button *resetTableBtn;

    static void staticCreateCB(Fl_Widget *w, void *data);
    static void staticDeleteCB(Fl_Widget *w, void *data);
    static void staticTruncateCB(Fl_Widget *w, void *data);
    static void staticResetCB(Fl_Widget *w, void *data);
};