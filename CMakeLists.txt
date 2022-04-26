cmake_minimum_required(VERSION 3.21)
project(macos-grafika-template)

set(CMAKE_CXX_STANDARD 11)

add_executable(${PROJECT_NAME} src/framework.cpp src/Skeleton.cpp)

target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
target_link_libraries(${PROJECT_NAME} "-framework GLUT")
