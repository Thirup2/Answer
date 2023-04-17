project(ForwardList)

add_library(${PROJECT_NAME} SHARED ForwardList.c)
target_link_libraries(${PROJECT_NAME} PUBLIC Coordinate)