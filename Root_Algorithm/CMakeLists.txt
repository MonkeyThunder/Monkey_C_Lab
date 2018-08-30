cmake_minimum_required(VERSION 3.10)
project(Root_Algorithm)

set(CMAKE_PREFIX_PATH ~/sdk_build)

find_package(aws-sdk-cpp)
add_definitions(-DUSE_IMPORT_EXPORT)

set(CMAKE_CXX_STANDARD 11)

add_executable(Root_Algorithm main.cpp Link_To_DB.cpp)