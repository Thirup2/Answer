project(Coordinate)

add_library(${PROJECT_NAME} SHARED Coordinate.cpp)

add_executable(${PROJECT_NAME}_test test.cpp)
target_link_libraries(${PROJECT_NAME}_test PUBLIC ${PROJECT_NAME})