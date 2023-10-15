project(LinkQueue)

add_library(${PROJECT_NAME} SHARED LinkQueue.c)
target_link_libraries(${PROJECT_NAME} PUBLIC Coords)