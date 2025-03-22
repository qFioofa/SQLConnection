g++ -std=c++17 \
    testgui.cpp \
    ../DataBase/DataBaseManager.cpp \
    ../DataBase/DataStruct.cpp \
    ../DataBase/DataInserter.cpp \
    ../DataBase/DataDeleter.cpp \
    ../DataBase/DataUpdater.cpp \
    ../DataBase/DataSearcher.cpp \
    ../DataBase/TableCleaner.cpp \
    InsertTab.cpp \
    DeleteTab.cpp \
    UpdateTab.cpp \
    OutputTab.cpp \
    SearchTab.cpp \
    GeneralInfoTab.cpp \
    MainConnection.cpp \
    -o testgui \
    $(fltk-config --cflags --ldflags) \
    -lsqlite3
./testgui
rm test.db
rm testgui