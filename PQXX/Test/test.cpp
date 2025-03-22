#include <cassert>
#include <iostream>

#include "TableField.h"
#include "TableKey.h"
#include "DataStruct.h"

#include "UserAuthorityHandler.h"

#include "DataBaseManager.h"

#include "DataInserter.h"
#include "DataDeleter.h"
#include "TableCleaner.h"
#include "DataUpdater.h"
#include "DataSearcher.h"
#include "TableCleaner.h"

typedef std::string str;

#define TABLE_NAME "Hello"

int main()
{
    // Info test
    SQLTableKey<str> t = SQLTableKey<str>("Key");
    SQLTableField<str> f = SQLTableField<str>("Field");
    assert("Key" == t.getKey());
    assert("Field" == f.getValue());

    // Manager test
    SQLDatabaseManager m = SQLDatabaseManager();
    assert(true == m.createDatabase(TABLE_NAME));

    // Inserter test
    SQLDataInserter<ContactData> inserter(m);

    assert(true == inserter.insertData(ContactData("134879354", "John", "None")));
    assert(true == inserter.insertData(ContactData("289308345", "Wick", "Finish")));

    // Searcher test
    SQLDataSearcher<ContactData> searcher(m);
    auto res = searcher.searchData(ContactData("134879354"));

    assert(res.size() > 0);
    for (size_t i = 0; i < res.size(); i++)
    {
        assert(res[i].phone_number.getKey() == "134879354");
    }

    res = searcher.searchData(ContactData("39583546"));

    assert(0 == res.size());

    // Authority test
    SQLUserAuthorityHandler auth = SQLUserAuthorityHandler(Role::Administrator);
    auth.setRole(Role::Moderator);

    // Delete test
    SQLDataDelete<str> del(m);
    assert(false == del.deleteByField(SQLTableField<str>("H")));
    assert(true == del.deleteByField(SQLTableField<str>("None")));

    // Updater test
    assert(true == inserter.insertData(ContactData("134879354", "John", "None")));

    SQLDataUpdater<ContactData> updater(m);
    assert(true == updater.updateData(SQLTableKey<str>("134879354"), ContactData("134879354", "Papa")));
    res = searcher.searchData(ContactData("134879354", "Papa"));

    assert(0 < res.size());
    for (size_t i = 0; i < res.size(); i++)
    {
        assert(res[i].full_name.getValue() == "Papa");
    }

    // Cleaner test
    SQLTableCleaner cleaner(m, __TABLE_NAME__);
    assert(true == cleaner.truncateTable());
    assert(true == cleaner.resetTable());

    assert(true == m.deleteDatabase(TABLE_NAME));
    return 0;
}

/*
#ifndef __
#define __
*/