cmake_minimum_required(VERSION 3.6)
project(Root_Algorithm)

set(CMAKE_PREFIX_PATH ~/sdk_build)

find_package(aws-sdk-cpp)
add_definitions(-DUSE_IMPORT_EXPORT)

set(CMAKE_CXX_STANDARD 14)

add_executable(BDRoot_Server Testing.cpp Source/Algorithm_PointToCenter.cpp Source/14_Root_Function.cpp Source/Global_Function.cpp Source/InsertDataToMap.cpp Source/Find_All_Route.cpp)


target_link_libraries(BDRoot_Server aws-cpp-sdk-core aws-cpp-sdk-dynamodb -v)