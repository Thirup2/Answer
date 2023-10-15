project(CycleQueue)

add_library(${PROJECT_NAME} SHARED CycleQueue.c)
target_link_libraries(${PROJECT_NAME} PUBLIC Coords)