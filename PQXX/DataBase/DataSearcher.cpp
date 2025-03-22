#include "DataSearcher.h"
#include "DataStruct.h"
#include <stdexcept>

template <typename T>
std::vector<T> SQLDataSearcher<T>::searchData(const T &filter) const
{
    std::vector<T> results;

    try
    {
        pqxx::work txn(conn);
        auto [query, params] = filter.toSearch();

        for (auto &p : params)
        {
            p = txn.quote(p);
        }

        size_t pos = 0;
        while ((pos = query.find('?', pos)) != std::string::npos)
        {
            query.replace(pos, 1, params.front());
            params.erase(params.begin());
        }

        pqxx::result res = txn.exec(query);

        for (const auto &row : res)
        {
            results.push_back(T::fromSQL(row));
        }

        txn.commit();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Search error: " << e.what() << std::endl;
    }

    return results;
}

template class SQLDataSearcher<ContactData>;