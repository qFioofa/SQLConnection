#include "SearchTab.h"
#include "../DataBase/TableKey.h"
#include "../DataBase/TableField.h"
#include "const.h"

template <typename T>
SearchTab<T>::SearchTab(int X, int Y, int W, int H, IOutputTab *output, const char *L)
    : ISearchTab<T, SQLDataSearcher<T>>(X, Y, W, H, L), outputTab(output)
{

    searchType = new Fl_Choice(__SEARCH_MARGIN__, Y + 10, W - 150, 25, "Search By:");
    searchType->add("Phone Number|Name|Note");
    searchType->value(0);

    searchInput = new Fl_Input(__SEARCH_MARGIN__, Y + 50, W - 200, 25, "Value:");

    searchBtn = new Fl_Button(__LEFT_MARGIN__, Y + 90, W - 20, 25, "Search");
    searchBtn->callback(searchCallback, this);
}

template <typename T>
void SearchTab<T>::connectSearcher(SQLDataSearcher<T> *s)
{
    this->searcher = s;
}

template <typename T>
std::vector<T> SearchTab<T>::performSearch()
{
    std::string value = searchInput->value();
    if (value.empty())
    {
        outputTab->appendOutput("Error: No search value provided!", false);
        return {};
    }

    T filter;
    switch (searchType->value())
    {
    case 0:
        filter.phone_number.setKey(value);
        break;
    case 1:
        filter.full_name.setValue(value);
        break;
    case 2:
        filter.note.setValue(value);
        break;
    }

    std::vector<T> results = this->searcher->searchData(filter);

    std::stringstream msg;
    msg << "Search Results (" << results.size() << "):";
    outputTab->appendOutput(msg.str(), true);

    for (const auto &result : results)
    {
        std::stringstream entry;
        entry << " - Phone: " << result.phone_number.getKey()
              << ", Name: " << result.full_name.getValue()
              << ", Note: " << result.note.getValue();
        outputTab->appendOutput(entry.str(), true);
    }

    return results;
}

template <typename T>
void SearchTab<T>::searchCallback(Fl_Widget *w, void *data)
{
    auto tab = static_cast<SearchTab<T> *>(data);
    tab->performSearch();
}

template <typename T>
void SearchTab<T>::deactivate()
{
    searchType->deactivate();
    searchInput->deactivate();
    searchBtn->deactivate();
}

template class SearchTab<ContactData>;