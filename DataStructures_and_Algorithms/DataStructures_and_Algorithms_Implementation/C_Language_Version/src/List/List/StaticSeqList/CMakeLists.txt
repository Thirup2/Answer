project(StaticSeqList)

add_library(${PROJECT_NAME} SHARED StaticSeqList.c)
target_link_libraries(${PROJECT_NAME} PUBLIC Coords)