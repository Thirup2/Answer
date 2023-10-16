project(TriMatrix)

add_library(${PROJECT_NAME} SHARED TriMatrix.c)
target_link_libraries(${PROJECT_NAME} PUBLIC Coords)