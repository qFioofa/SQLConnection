#pragma once
#include <FL/Fl_Group.H>
#include <string>

class IMainPanel
{
public:
    virtual ~IMainPanel() = default;

    virtual bool createDatabase(const std::string &dbName) = 0;
    virtual bool deleteDatabase(const std::string &dbName) = 0;
    virtual bool updateTuple(const std::string &key, const std::string &newName, const std::string &newNote) = 0;
};