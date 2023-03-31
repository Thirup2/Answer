cmake_minimum_required(VERSION 3.24)
project(大话数据结构C语言版)

set(CMAKE_C_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/share)

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/share)

add_subdirectory(${PROJECT_SOURCE_DIR}/src/0.Prepare/1.ElemType)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/0.Prepare/2.Bag)