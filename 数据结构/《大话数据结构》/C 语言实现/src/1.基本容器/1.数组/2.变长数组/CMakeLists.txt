project(Vector)

add_library(${PROJECT_NAME} SHARED Vector.c)
target_link_libraries(${PROJECT_NAME} PUBLIC Coordinate)