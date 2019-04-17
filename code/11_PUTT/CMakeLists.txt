cmake_minimum_required(VERSION 3.13)

project(11_PUTT_main)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(11_PUTT_main
			src/main.cpp
			src/OneByOneMatrix.h
			src/OneByOneMatrix.cpp
)

include_directories(
        ../helpers/
        src/
)

set_target_properties(11_PUTT_main PROPERTIES SUFFIX ".out")