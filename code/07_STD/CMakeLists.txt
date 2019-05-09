cmake_minimum_required(VERSION 3.13)

project(07_stacks)
project(07_strings)
project(07_mod)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(07_stacks
			src/main.cpp
			src/genericStack.hpp
			src/intStack.cpp
			src/intStack.hpp
)

add_executable(07_strings
		src/testat.cpp)

add_executable(07_mod
		src/modifikation.cpp)

include_directories(
        ../helpers/
        src/
)

set_target_properties(07_stacks PROPERTIES SUFFIX ".out")
set_target_properties(07_strings PROPERTIES SUFFIX ".out")
set_target_properties(07_mod PROPERTIES SUFFIX ".out")
