#include "DataDeleter.h"
#include <stdexcept>

template <typename T>
SQLDataDelete<T>::SQLDataDelete(SQLDatabaseManager &manager)
    : conn(manager.getHandle()) {}

template <typename T>
bool SQLDataDelete<T>::deleteByKey(const ITableKey<T> &key)
{
    if (!key.isValid())
        return false;

    try
    {
        pqxx::work txn(conn);
        const std::string query =
            "DELETE FROM " + txn.quote_name(__TABLE_NAME__) +
            " WHERE phone_number = " + txn.quote(key.getKey());

        pqxx::result res = txn.exec(query);
        txn.commit();
        return res.affected_rows() > 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Delete error: " << e.what() << std::endl;
        return false;
    }
}

template <typename T>
bool SQLDataDelete<T>::deleteByField(const ITableField<T> &field)
{
    if (field.getValue().empty())
        return false;

    try
    {
        pqxx::work txn(conn);
        const std::string value = txn.quote(field.getValue());
        const std::string query =
            "DELETE FROM " + txn.quote_name(__TABLE_NAME__) +
            " WHERE full_name = " + value + " OR note = " + value;

        pqxx::result res = txn.exec(query);
        txn.commit();
        return res.affected_rows() > 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Delete error: " << e.what() << std::endl;
        return false;
    }
}

template class SQLDataDelete<std::string>;