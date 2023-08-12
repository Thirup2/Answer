cmake_minimum_required(VERSION 3.25)
project(DSA_Implementation_In_C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

include_directories(${PROJECT_SOURCE_DIR}/prepare/include ${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

add_subdirectory(${PROJECT_SOURCE_DIR}/prepare/src/Coords)

add_subdirectory(${PROJECT_SOURCE_DIR}/src/LinearList/List)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/LinearList/List/StaticSeqList)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/LinearList/List/DynamicSeqList)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/LinearList/List/SingleLinkList)