#include "InsertTab.h"
#include "const.h"

template <typename T>
InsertTab<T>::InsertTab(int X, int Y, int W, int H, IOutputTab *output, const char *L)
    : IInsertTab<T, SQLDataInserter<T>>(X, Y, W, H, L), outputTab(output)
{
    phoneInput = new Fl_Input(__INSERT_MARGINE__, 20, W - __INSERT_MARGINE__, 25, "Phone:");
    nameInput = new Fl_Input(__INSERT_MARGINE__, 60, W - __INSERT_MARGINE__, 25, "Name:");
    noteInput = new Fl_Input(__INSERT_MARGINE__, 100, W - __INSERT_MARGINE__, 25, "Note:");
    insertBtn = new Fl_Button(__LEFT_MARGIN__, 140, W - __LEFT_MARGIN__, 25, "Insert Record");
    insertBtn->callback(insertCallback, this);
}

template <typename T>
void InsertTab<T>::connectInserter(SQLDataInserter<T> *ins)
{
    this->inserter = ins;
}

template <typename T>
bool InsertTab<T>::executeInsert()
{
    std::string phone = phoneInput->value();
    std::string name = nameInput->value();
    std::string note = noteInput->value();

    T data(phone, name, note);
    bool success = this->inserter->insertData(data);

    std::stringstream msg;
    msg << "Insert: " << (success ? "Success" : "Failed")
        << ". Data: " << phone << ", " << name << ", " << note;
    outputTab->appendOutput(msg.str(), success);

    return success;
}

template <typename T>
void InsertTab<T>::insertCallback(Fl_Widget *w, void *data)
{
    auto tab = static_cast<InsertTab<T> *>(data);
    tab->executeInsert();
}

template <typename T>
void InsertTab<T>::deactivate()
{
    phoneInput->deactivate();
    nameInput->deactivate();
    noteInput->deactivate();
    insertBtn->deactivate();
}

template class InsertTab<ContactData>;