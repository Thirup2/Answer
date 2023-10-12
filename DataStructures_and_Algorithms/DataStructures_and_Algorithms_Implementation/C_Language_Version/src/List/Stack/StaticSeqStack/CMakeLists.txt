project(StaticSeqStack)

add_library(${PROJECT_NAME} SHARED StaticSeqStack.c)
target_link_libraries(${PROJECT_NAME} PUBLIC Coords)