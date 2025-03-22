g++ test.cpp DataBaseManager.cpp \
    DataStruct.cpp \
    DataInserter.cpp \
    UserAuthorityHandler.cpp \
    DataDeleter.cpp \
    DataSearcher.cpp \
    DataUpdater.cpp \
    TableCleaner.cpp \
    -o test -lsqlite3 -std=c++17
./test
rm test
rm Hello