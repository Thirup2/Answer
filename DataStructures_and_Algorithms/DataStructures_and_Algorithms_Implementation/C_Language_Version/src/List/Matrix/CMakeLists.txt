project(Matrix)

add_executable(${PROJECT_NAME} Matrix.c)
target_link_libraries(${PROJECT_NAME} PUBLIC TriDiaMatrix)