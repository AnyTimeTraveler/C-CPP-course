cmake_minimum_required(VERSION 3.13)

project(07_STD_main)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(07_STD_main
			src/main.cpp
			src/genericStack.hpp
			src/intStack.cpp
			src/intStack.hpp
			src/grundgeruest.cpp
)

include_directories(
        ../helpers/
        src/
)

set_target_properties(07_STD_main PROPERTIES SUFFIX ".out")