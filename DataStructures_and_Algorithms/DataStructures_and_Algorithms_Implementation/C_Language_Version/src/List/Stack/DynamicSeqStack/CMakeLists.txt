project(DynamicSeqStack)

add_library(${PROJECT_NAME} SHARED DynamicSeqStack.c)
target_link_libraries(${PROJECT_NAME} PUBLIC Coords)