cmake_minimum_required(VERSION 3.25)
project(数据结构及算法实现——C语言版)

set(CMAKE_C_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/share)

include_directories(${PROJECT_SOURCE_DIR}/Prepare/include ${PROJECT_SOURCE_DIR}/DS_APIs)
link_directories(${PROJECT_SOURCE_DIR}/share)

add_subdirectory(${PROJECT_SOURCE_DIR}/Prepare/src/Coords)

add_subdirectory(${PROJECT_SOURCE_DIR}/src/1.集合/1.背包)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/1.集合/2.链串)

add_subdirectory(${PROJECT_SOURCE_DIR}/src/2.基本线性表/1.静态顺序表)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/2.基本线性表/2.动态顺序表)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/2.基本线性表/3.单链表)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/2.基本线性表/4.双向链表)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/3.栈/1.顺序栈)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/3.栈/2.链栈)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/4.队列/1.循环队列)