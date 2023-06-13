cmake_minimum_required(VERSION 3.25)
project(数据结构及算法实现——C++版)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/share)

include_directories(${PROJECT_SOURCE_DIR}/Prepare/include ${PROJECT_SOURCE_DIR}/DS_APIs)
link_directories(${PROJECT_SOURCE_DIR}/share)

add_subdirectory(${PROJECT_SOURCE_DIR}/Prepare/src/Coords)

add_subdirectory(${PROJECT_SOURCE_DIR}/src/1.集合/1.背包)