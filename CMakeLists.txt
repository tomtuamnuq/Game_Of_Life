cmake_minimum_required(VERSION 3.0.0)
project(GameOfLife VERSION 0.1.0)

include(CTest)
enable_testing()
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(include)
file(GLOB SOURCES "src/*.cpp")


add_executable(GameOfLife main.cpp ${SOURCES})
target_link_libraries(GameOfLife ${SDL2_LIBRARIES})
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
