project(CycleLinkList)

add_library(${PROJECT_NAME} SHARED CycleLinkList.c)
target_link_libraries(${PROJECT_NAME} PUBLIC Coords)