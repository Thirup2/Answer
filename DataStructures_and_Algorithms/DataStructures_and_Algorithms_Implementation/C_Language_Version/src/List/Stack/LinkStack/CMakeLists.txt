project(LinkStack)

add_library(${PROJECT_NAME} SHARED LinkStack.c)
target_link_libraries(${PROJECT_NAME} PUBLIC Coords)