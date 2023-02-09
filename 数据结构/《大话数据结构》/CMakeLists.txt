cmake_minimum_required(VERSION 3.24)
project(DataStructures)

set(CMAKE_C_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/share)

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/share)

add_subdirectory(${PROJECT_SOURCE_DIR}/src/0.Head/ElemType)

add_subdirectory(${PROJECT_SOURCE_DIR}/src/1.数组/1.定容数组)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/1.数组/2.变长数组)

add_subdirectory(${PROJECT_SOURCE_DIR}/src/2.链表/1.单链表)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/2.链表/2.双向链表)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/2.链表/3.循环链表)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/2.链表/4.双向循环链表)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/2.链表/5.静态链表)

add_subdirectory(${PROJECT_SOURCE_DIR}/src/3.栈/1.顺序栈)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/3.栈/2.链栈)

add_subdirectory(${PROJECT_SOURCE_DIR}/src/4.队列/1.循环队列)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/4.队列/2.链队列)

add_subdirectory(${PROJECT_SOURCE_DIR}/src/5.串/1.顺序串)

add_subdirectory(${PROJECT_SOURCE_DIR}/src/6.树/1.顺序二叉树)