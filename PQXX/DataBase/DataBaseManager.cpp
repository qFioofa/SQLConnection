#include "DataBaseManager.h"
#include <iostream>
#include <stdexcept>

bool SQLDatabaseManager::createDatabase(const std::string &dbName)
{
    try
    {
        pqxx::connection admin_conn(connection_string + " dbname=postgres");
        pqxx::work txn(admin_conn);

        txn.exec("CREATE DATABASE " + txn.quote_name(dbName));
        txn.commit();

        conn = std::make_unique<pqxx::connection>(connection_string + " dbname=" + dbName);

        pqxx::work table_txn(*conn);
        table_txn.exec(
            "CREATE TABLE IF NOT EXISTS " + table_txn.quote_name(__TABLE_NAME__) + " ("
                                                                                   "id SERIAL PRIMARY KEY,"
                                                                                   "full_name TEXT NOT NULL,"
                                                                                   "phone_number TEXT UNIQUE NOT NULL,"
                                                                                   "note TEXT"
                                                                                   ")");
        table_txn.commit();
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Database error: " << e.what() << std::endl;
        return false;
    }
}

bool SQLDatabaseManager::deleteDatabase(const std::string &dbName)
{
    try
    {
        pqxx::connection admin_conn(connection_string + " dbname=postgres");
        pqxx::work txn(admin_conn);

        // Завершение всех соединений с БД
        txn.exec("REVOKE CONNECT ON DATABASE " + txn.quote_name(dbName) + " FROM PUBLIC");
        txn.exec(
            "SELECT pg_terminate_backend(pg_stat_activity.pid) "
            "FROM pg_stat_activity "
            "WHERE pg_stat_activity.datname = " +
            txn.quote(dbName));

        txn.exec("DROP DATABASE IF EXISTS " + txn.quote_name(dbName));
        txn.commit();
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Database error: " << e.what() << std::endl;
        return false;
    }
}