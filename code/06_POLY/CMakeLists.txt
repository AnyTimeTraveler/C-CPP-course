cmake_minimum_required(VERSION 3.13)

project(06_POLY)
project(06_SHAPES)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(06_POLY
			src/main_mp5_POLY.cpp
)

add_executable(06_SHAPES
		src/shapes.cpp
		../helpers/AnsiConsole.cpp)

include_directories(
        ../helpers/
        src/
)

set_target_properties(06_POLY PROPERTIES SUFFIX ".out")
set_target_properties(06_SHAPES PROPERTIES SUFFIX ".out")
