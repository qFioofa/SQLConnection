#include "TableCleaner.h"
#include <stdexcept>

SQLTableCleaner::SQLTableCleaner(SQLDatabaseManager &manager, const std::string &table)
    : conn(manager.getHandle()), tableName(table)
{
        if (!fetchTableSchema())
        {
                throw std::runtime_error("Failed to fetch table schema");
        }
}

bool SQLTableCleaner::truncateTable()
{
        try
        {
                pqxx::work txn(conn);
                txn.exec("TRUNCATE TABLE " + txn.quote_name(tableName));
                txn.commit();
                return true;
        }
        catch (const std::exception &e)
        {
                std::cerr << "Truncate error: " << e.what() << std::endl;
                return false;
        }
}

bool SQLTableCleaner::resetTable()
{
        try
        {
                pqxx::work txn(conn);

                txn.exec("DROP TABLE IF EXISTS " + txn.quote_name(tableName));

                txn.exec(tableSchema);

                txn.commit();
                return true;
        }
        catch (const std::exception &e)
        {
                std::cerr << "Reset error: " << e.what() << std::endl;
                return false;
        }
}

bool SQLTableCleaner::fetchTableSchema()
{
        try
        {
                pqxx::work txn(conn);
                pqxx::result res = txn.exec(
                    "SELECT pg_get_tabledef(" + txn.quote(tableName) + ")");

                if (!res.empty())
                {
                        tableSchema = res[0][0].as<std::string>();
                        return true;
                }
                return false;
        }
        catch (...)
        {
                return false;
        }
}