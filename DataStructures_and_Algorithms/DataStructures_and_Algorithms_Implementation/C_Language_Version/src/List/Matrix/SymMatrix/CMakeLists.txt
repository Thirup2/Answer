project(SymMatrix)

add_library(${PROJECT_NAME} SHARED SymMatrix.c)
target_link_libraries(${PROJECT_NAME} PUBLIC Coords)