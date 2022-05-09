cmake_minimum_required(VERSION 3.21)
project(macos-grafika-template)

set(CMAKE_CXX_STANDARD 11)
file(GLOB project_SRC CONFIGURE_DEPENDS "./src/*.h" "./src/*.cpp")
add_executable(${PROJECT_NAME} ${project_SRC})

target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
target_link_libraries(${PROJECT_NAME} "-framework GLUT")

target_compile_definitions(${PROJECT_NAME} PRIVATE GL_SILENCE_DEPRECATION)
