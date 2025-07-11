cmake_minimum_required(VERSION 3.10)
project(stablecoin_tracker)

set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/modules)

add_executable(tracker
    main.cpp
    modules/price_fetcher.cpp
    modules/sqlite_logger.cpp
    modules/risk_model.cpp
    modules/email_notifier.cpp
)

# CURL
find_package(CURL REQUIRED)
target_link_libraries(tracker PRIVATE CURL::libcurl)

# SQLite3 manually
set(SQLite3_INCLUDE_DIR "C:/msys64/ucrt64/include")
set(SQLite3_LIBRARY "C:/msys64/ucrt64/lib/libsqlite3.dll.a")
include_directories(${SQLite3_INCLUDE_DIR})
target_link_libraries(tracker PRIVATE ${SQLite3_LIBRARY})
find_package(CURL REQUIRED)
target_link_libraries(tracker PRIVATE CURL::libcurl)
