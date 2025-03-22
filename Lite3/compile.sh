g++ -std=c++17 \
    main.cpp \
    ./Application/CoreGUI.cpp \
    ./DataBase/DataBaseManager.cpp \
    ./DataBase/DataStruct.cpp \
    ./DataBase/DataInserter.cpp \
    ./DataBase/DataDeleter.cpp \
    ./DataBase/DataUpdater.cpp \
    ./DataBase/DataSearcher.cpp \
    ./DataBase/TableCleaner.cpp \
    ./GUI/InsertTab.cpp \
    ./GUI/DeleteTab.cpp \
    ./GUI/UpdateTab.cpp \
    ./GUI/OutputTab.cpp \
    ./GUI/SearchTab.cpp \
    ./GUI/GeneralInfoTab.cpp \
    ./GUI/MainConnection.cpp \
    -o App \
    $(fltk-config --cflags --ldflags) \
    -lsqlite3
