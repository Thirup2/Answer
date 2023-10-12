project(DoubleLinkList)

add_library(${PROJECT_NAME} SHARED DoubleLinkList.c)
target_link_libraries(${PROJECT_NAME} PUBLIC Coords)