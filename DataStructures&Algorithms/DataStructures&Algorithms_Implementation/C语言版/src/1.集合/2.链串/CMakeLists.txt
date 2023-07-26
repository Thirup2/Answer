project(Bunch)

add_library(${PROJECT_NAME} SHARED Bunch.c)
target_link_libraries(${PROJECT_NAME} PUBLIC Coords)

add_executable(${PROJECT_NAME}_test test.c)
target_link_libraries(${PROJECT_NAME}_test PUBLIC Bunch)