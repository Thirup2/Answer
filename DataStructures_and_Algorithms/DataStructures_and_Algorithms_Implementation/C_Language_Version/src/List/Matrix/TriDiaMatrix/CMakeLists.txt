project(TriDiaMatrix)

add_library(${PROJECT_NAME} SHARED TriDiaMatrix.c)
target_link_libraries(${PROJECT_NAME} PUBLIC Coords)