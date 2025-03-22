#include "DataUpdater.h"
#include <stdexcept>

template <typename T>
SQLDataUpdater<T>::SQLDataUpdater(SQLDatabaseManager &manager)
    : conn(manager.getHandle()) {}

template <typename T>
bool SQLDataUpdater<T>::updateData(const ITableKey<std::string> &key, const T &newValue)
{
    if (!key.isValid())
        return false;

    try
    {
        pqxx::work txn(conn);

        const std::string query =
            "UPDATE " + txn.quote_name(__TABLE_NAME__) + " SET "
                                                         "full_name = " +
            txn.quote(newValue.full_name.getValue()) + ", "
                                                       "note = " +
            txn.quote(newValue.note.getValue()) + " "
                                                  "WHERE phone_number = " +
            txn.quote(key.getKey());

        pqxx::result res = txn.exec(query);
        txn.commit();

        return res.affected_rows() > 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Update error: " << e.what() << std::endl;
        return false;
    }
}

template class SQLDataUpdater<ContactData>;