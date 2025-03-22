#include "UpdateTab.h"
#include "const.h"

template <typename T>
UpdaterTab<T>::UpdaterTab(int X, int Y, int W, int H, IOutputTab *output, const char *L)
    : IUpdateTab<T, SQLDataUpdater<T>>(X, Y, W, H, L), outputTab(output)
{
    keyInput = new Fl_Input(__UPDATE_MARGINE__, Y + 10, W - __UPDATE_MARGINE__, 25, "Phone (Key):");
    nameInput = new Fl_Input(__UPDATE_MARGINE__, Y + 50, W - __UPDATE_MARGINE__, 25, "New Name:");
    noteInput = new Fl_Input(__UPDATE_MARGINE__, Y + 90, W - __UPDATE_MARGINE__, 25, "New Note:");
    updateBtn = new Fl_Button(__LEFT_MARGIN__, Y + 130, W - __LEFT_MARGIN__, 25, "Update Record");
    updateBtn->callback(updateCallback, this);
}

template <typename T>
void UpdaterTab<T>::connectUpdater(SQLDataUpdater<T> *upd)
{
    this->updater = upd;
}

template <typename T>
bool UpdaterTab<T>::executeUpdate()
{
    std::string key = keyInput->value();
    std::string newName = nameInput->value();
    std::string newNote = noteInput->value();

    SQLTableKey<std::string> updateKey(key);
    T newValues("", newName, newNote);

    bool success = this->updater->updateData(updateKey, newValues);

    std::stringstream msg;
    msg << "Update: " << (success ? "Success" : "Failed")
        << ". Key=" << key
        << ", New Name=" << newName
        << ", New Note=" << newNote;

    outputTab->appendOutput(msg.str(), success);
    return success;
}

template <typename T>
void UpdaterTab<T>::updateCallback(Fl_Widget *w, void *data)
{
    auto tab = static_cast<UpdaterTab<T> *>(data);
    tab->executeUpdate();
}

template <typename T>
void UpdaterTab<T>::deactivate()
{
    keyInput->deactivate();
    nameInput->deactivate();
    noteInput->deactivate();
    updateBtn->deactivate();
}

template class UpdaterTab<ContactData>;