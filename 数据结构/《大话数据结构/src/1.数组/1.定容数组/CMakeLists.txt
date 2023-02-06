project(ConstVolArray)

add_library(${PROJECT_NAME} SHARED ${PROJECT_NAME}.c)
target_link_libraries(${PROJECT_NAME} PUBLIC ElemType)

add_executable(${PROJECT_NAME}_test test.c)
target_link_libraries(${PROJECT_NAME}_test ${PROJECT_NAME})