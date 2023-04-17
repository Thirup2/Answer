project(ConstantVolumeArray)

add_library(${PROJECT_NAME} SHARED ConstantVolumeArray.c)
target_link_libraries(${PROJECT_NAME} PUBLIC Coordinate)