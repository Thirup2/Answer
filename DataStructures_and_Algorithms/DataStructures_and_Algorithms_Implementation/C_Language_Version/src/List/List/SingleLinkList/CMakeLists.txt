project(SingleLinkList)

add_library(${PROJECT_NAME} SHARED SingleLinkList.c)
target_link_libraries(${PROJECT_NAME} PUBLIC Coords)