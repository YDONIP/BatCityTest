cmake_minimum_required(VERSION 3.18 FATAL_ERROR)
set(PN BatCityTest)
project(BattleCity)

add_executable(${PN} src/main.cpp)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory(external/glfw)

target_link_libraries(${PN} glfw)

add_subdirectory(external/glad)
target_link_libraries(${PN} glad)