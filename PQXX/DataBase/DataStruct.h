#pragma once
#include "TableKey.h"
#include "TableField.h"
#include <pqxx/pqxx>
#include <string>
#include <vector>

struct ContactData
{
    SQLTableKey<std::string> phone_number;
    SQLTableField<std::string> full_name;
    SQLTableField<std::string> note;

    ContactData() = default;
    ContactData(const std::string &phone, const std::string &name, const std::string &noteText)
        : phone_number(phone), full_name(name), note(noteText) {}

    ContactData(const std::string &phone, const std::string &name)
        : phone_number(phone), full_name(name), note("") {}

    ContactData(const std::string &phone)
        : phone_number(phone), full_name(""), note("") {}

    std::pair<std::string, std::vector<std::string>> toInsert() const;
    std::pair<std::string, std::vector<std::string>> toSearch() const;

    static ContactData fromSQL(const pqxx::row &row);
};