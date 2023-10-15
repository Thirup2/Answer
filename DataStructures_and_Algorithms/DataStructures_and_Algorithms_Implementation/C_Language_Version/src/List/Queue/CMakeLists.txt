project(Queue)

add_executable(${PROJECT_NAME} Queue.c)
target_link_libraries(${PROJECT_NAME} PUBLIC CycleQueue)