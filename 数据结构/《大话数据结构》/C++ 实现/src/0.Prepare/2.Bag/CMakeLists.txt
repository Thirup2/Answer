project(Bag)

add_library(${PROJECT_NAME} SHARED Bag.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC Coordinate)

add_executable(${PROJECT_NAME}_test test.cpp)
target_link_libraries(${PROJECT_NAME}_test PUBLIC ${PROJECT_NAME})