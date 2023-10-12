project(Stack)

add_executable(${PROJECT_NAME} Stack.c)
target_link_libraries(${PROJECT_NAME} PUBLIC LinkStack)