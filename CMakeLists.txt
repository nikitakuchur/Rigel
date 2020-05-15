cmake_minimum_required(VERSION 3.16)
project(rigel)

set(CMAKE_CXX_STANDARD 14)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

file(GLOB RIGEL_SOURCES src/*.cpp src/glutils/*.cpp)
#file(GLOB RIGEL_HEADERS src/*.h src/glutils/*.h)
add_executable(${PROJECT_NAME} ${RIGEL_SOURCES})

add_subdirectory(deps/glad)
target_link_libraries(${PROJECT_NAME} glad)

add_subdirectory(deps/glfw)
target_link_libraries(${PROJECT_NAME} glfw)
find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} OpenGL::GL)

add_subdirectory(deps/glm)
target_link_libraries(${PROJECT_NAME} glm)
