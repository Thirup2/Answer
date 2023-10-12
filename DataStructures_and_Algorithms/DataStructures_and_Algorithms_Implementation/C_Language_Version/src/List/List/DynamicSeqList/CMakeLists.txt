project(DynamicSeqList)

add_library(${PROJECT_NAME} SHARED DynamicSeqList.c)
target_link_libraries(${PROJECT_NAME} PUBLIC Coords)