project(List)

add_executable(${PROJECT_NAME} List.c)
target_link_libraries(${PROJECT_NAME} PUBLIC Coords SingleLinkList)