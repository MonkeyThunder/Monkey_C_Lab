cmake_minimum_required(VERSION 3.6)
project(Root_Algorithm)

set(CMAKE_PREFIX_PATH ~/sdk_build)

find_package(aws-sdk-cpp)
add_definitions(-DUSE_IMPORT_EXPORT)

set(CMAKE_CXX_STANDARD 14)

#add_executable(Root_Algorithm Test_TableInfo.cpp)
#add_executable(Root_Algorithm Test_ListTable.cpp)
#add_executable(Root_Algorithm Test_GetItem.cpp)
#add_executable(Root_Algorithm Test_Files/Test_PutItem.cpp)
#add_executable(Root_Algorithm Test_Files/Test_C++Server.cpp)
add_executable(Root_Algorithm Test_Files/Test_C++Client.cpp)


target_link_libraries(Root_Algorithm aws-cpp-sdk-core aws-cpp-sdk-dynamodb -v)