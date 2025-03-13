cmake_minimum_required(VERSION 3.21)
project(macos-grafika-template)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
file(GLOB project_SRC CONFIGURE_DEPENDS "./src/*.h" "./src/*.cpp")
add_executable(${PROJECT_NAME} ${project_SRC})
aux_source_directory(./src/ SRC_LIST)


# Find and link GLFW
find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

target_link_libraries(${PROJECT_NAME} glfw OpenGL::GL)

# glad
set(GLAD_DIR "./src/Glad")
add_library("glad" "${GLAD_DIR}/src/glad.c")
target_include_directories("glad" PRIVATE "${GLAD_DIR}/include")
target_include_directories(${PROJECT_NAME} PRIVATE "${GLAD_DIR}/include")
target_link_libraries(${PROJECT_NAME} "glad" "${CMAKE_DL_LIBS}")

set(glm_DIR ./src/glm)
find_package(glm REQUIRED)
target_link_libraries(${PROJECT_NAME} glm::glm)

if(APPLE)
    set_target_properties(${PROJECT_NAME} PROPERTIES MACOSX_BUNDLE TRUE)
endif()


# macOS-specific frameworks
target_link_libraries(${PROJECT_NAME} "-framework Cocoa" "-framework IOKit" "-framework CoreVideo")

target_compile_definitions(${PROJECT_NAME} PRIVATE GL_SILENCE_DEPRECATION)
