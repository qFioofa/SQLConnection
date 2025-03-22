#include "DataStruct.h"

std::pair<std::string, std::vector<std::string>> ContactData::toInsert() const
{
    return {
        "INSERT INTO contacts(full_name, phone_number, note) VALUES(?, ?, ?)",
        {full_name.getValue(), phone_number.getKey(), note.getValue()}};
}

std::pair<std::string, std::vector<std::string>> ContactData::toSearch() const
{
    std::string query = "SELECT * FROM contacts WHERE 1=1";
    std::vector<std::string> params;

    if (!full_name.getValue().empty())
    {
        query += " AND full_name LIKE ?";
        params.push_back("%" + full_name.getValue() + "%");
    }
    if (phone_number.isValid())
    {
        query += " AND phone_number = ?";
        params.push_back(phone_number.getKey());
    }
    if (!note.getValue().empty())
    {
        query += " AND note LIKE ?";
        params.push_back("%" + note.getValue() + "%");
    }

    return {query, params};
}

ContactData ContactData::fromSQL(sqlite3_stmt *stmt)
{
    return ContactData(
        reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2)),
        reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)),
        reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0)));
}