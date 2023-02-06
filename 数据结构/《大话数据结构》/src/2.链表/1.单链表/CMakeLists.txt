project(SingleLinkList)

add_library(${PROJECT_NAME} SHARED SingleLinkList.c)
target_link_libraries(${PROJECT_NAME} PUBLIC ElemType)

add_executable(${PROJECT_NAME}_test test.c)
target_link_libraries(${PROJECT_NAME}_test PUBLIC ${PROJECT_NAME})