project(Coordinate)

add_library(${PROJECT_NAME} SHARED Coordinate.c)

add_executable(${PROJECT_NAME}_test test.c)
target_link_libraries(${PROJECT_NAME}_test PUBLIC ${PROJECT_NAME})