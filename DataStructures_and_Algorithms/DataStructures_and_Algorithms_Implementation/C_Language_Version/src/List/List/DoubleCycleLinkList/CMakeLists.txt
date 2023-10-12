project(DoubleCycleLinkList)

add_library(${PROJECT_NAME} SHARED DoubleCycleLinkList.c)
target_link_libraries(${PROJECT_NAME} PUBLIC Coords)