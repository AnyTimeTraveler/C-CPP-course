cmake_minimum_required(VERSION 3.13)
project(03_FLOW_a)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(03_FLOW_a
        src/main_mp2_FLOW_a.cpp
        ../helpers/AnsiConsole.cpp)

include_directories(
        ../helpers/
        src
)

set_target_properties(03_FLOW_a PROPERTIES SUFFIX ".out")
