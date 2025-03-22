#include "DataInserter.h"
#include "DataStruct.h"
#include <stdexcept>

template <typename T>
bool SQLDataInserter<T>::insertData(const T &data)
{
    try
    {
        pqxx::work txn(conn);
        auto [query, params] = data.toInsert();

        for (auto &p : params)
        {
            p = txn.quote(p);
        }

        size_t pos = 0;
        size_t param_idx = 0;
        while ((pos = query.find('?', pos)) != std::string::npos)
        {
            query.replace(pos, 1, params[param_idx++]);
            pos += params[param_idx - 1].size();
        }

        txn.exec(query);
        txn.commit();
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Insert error: " << e.what() << std::endl;
        return false;
    }
}

template class SQLDataInserter<ContactData>;