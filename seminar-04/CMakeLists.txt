cmake_minimum_required(VERSION 3.14)

project(mipt-cpp-advanced-seminar-04 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(task-01 ${CMAKE_SOURCE_DIR}/src/task-01.cpp)
target_sources(task-01 PRIVATE ${CMAKE_SOURCE_DIR}/include/task-01.h)

add_executable(task-02 ${CMAKE_SOURCE_DIR}/src/task-02.cpp)
target_sources(task-02 PRIVATE ${CMAKE_SOURCE_DIR}/include/task-02.h)

add_executable(task-03 ${CMAKE_SOURCE_DIR}/src/task-03.cpp)
target_sources(task-03 PRIVATE ${CMAKE_SOURCE_DIR}/include/task-03.h)
