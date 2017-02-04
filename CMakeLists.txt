cmake_minimum_required (VERSION 2.6)
project (generals)

find_package(Threads)

include_directories ("${PROJECT_SOURCE_DIR}/socket.io-client-cpp")
include_directories ("${PROJECT_SOURCE_DIR}/socket.io-client-cpp/src")
add_subdirectory (socket.io-client-cpp)

add_executable(main main.cc network.cc)
target_link_libraries(main sioclient pthread)
