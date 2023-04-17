project(List)

add_library(${PROJECT_NAME} SHARED List.c)
target_link_libraries(${PROJECT_NAME} PUBLIC Coordinate)