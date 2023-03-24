project(ArrayBiTree)

add_library(${PROJECT_NAME} SHARED ArrayBiTree.c)
target_link_libraries(${PROJECT_NAME} PUBLIC ElemType m)

add_executable(${PROJECT_NAME}_test test.c)
target_link_libraries(${PROJECT_NAME}_test PUBLIC ${PROJECT_NAME})

