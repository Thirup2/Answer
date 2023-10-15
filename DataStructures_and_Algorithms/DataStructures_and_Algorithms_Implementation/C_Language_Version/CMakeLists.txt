cmake_minimum_required(VERSION 3.25)
project(DSA_Implementation_In_C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

include_directories(${PROJECT_SOURCE_DIR}/prepare/include)
include_directories(${PROJECT_SOURCE_DIR}/include/List/List)
include_directories(${PROJECT_SOURCE_DIR}/include/List/Stack)
include_directories(${PROJECT_SOURCE_DIR}/include/List/Queue)

link_directories(${PROJECT_SOURCE_DIR}/lib)

add_subdirectory(${PROJECT_SOURCE_DIR}/prepare/src/Coords)

add_subdirectory(${PROJECT_SOURCE_DIR}/src/List/List)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/List/List/StaticSeqList)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/List/List/DynamicSeqList)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/List/List/SingleLinkList)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/List/List/DoubleLinkList)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/List/List/CycleLinkList)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/List/List/DoubleCycleLinkList)

add_subdirectory(${PROJECT_SOURCE_DIR}/src/List/Stack)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/List/Stack/StaticSeqStack)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/List/Stack/DynamicSeqStack)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/List/Stack/LinkStack)

add_subdirectory(${PROJECT_SOURCE_DIR}/src/List/Queue)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/List/Queue/CycleQueue)