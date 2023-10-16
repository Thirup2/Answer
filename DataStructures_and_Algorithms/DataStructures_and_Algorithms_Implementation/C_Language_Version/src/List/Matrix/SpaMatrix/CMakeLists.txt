project(SpaMatrix)

add_library(${PROJECT_NAME} SHARED SpaMatrix.c)
target_link_libraries(${PROJECT_NAME} PUBLIC Coords)