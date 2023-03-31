project(Bag)

add_library(${PROJECT_NAME} SHARED Bag.c)
target_link_libraries(${PROJECT_NAME} PUBLIC Coordinate)

add_executable(${PROJECT_NAME}_test test.c)
target_link_libraries(${PROJECT_NAME}_test PUBLIC ${PROJECT_NAME})