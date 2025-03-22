#include "DataStruct.h"

std::pair<std::string, std::vector<std::string>> ContactData::toInsert() const
{
    return {
        "INSERT INTO contacts(full_name, phone_number, note) VALUES($1, $2, $3)",
        {full_name.getValue(), phone_number.getKey(), note.getValue()}};
}

std::pair<std::string, std::vector<std::string>> ContactData::toSearch() const
{
    std::string query = "SELECT * FROM contacts WHERE 1=1";
    std::vector<std::string> params;

    if (!full_name.getValue().empty())
    {
        query += " AND full_name LIKE $1";
        params.push_back("%" + full_name.getValue() + "%");
    }
    if (phone_number.isValid())
    {
        query += " AND phone_number = $2";
        params.push_back(phone_number.getKey());
    }
    if (!note.getValue().empty())
    {
        query += " AND note LIKE $3";
        params.push_back("%" + note.getValue() + "%");
    }

    return {query, params};
}

ContactData ContactData::fromSQL(const pqxx::row &row)
{
    return ContactData(
        row["phone_number"].as<std::string>(),
        row["full_name"].as<std::string>(),
        row["note"].as<std::string>());
}