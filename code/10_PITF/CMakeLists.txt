cmake_minimum_required(VERSION 3.13)

project(10_PITF_main_objectSlicing)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(10_PITF_main_objectSlicing
			src/main_objectSlicing.cpp
			src/banking_base_rawptr.cpp
			src/doubleDelete
)

include_directories(
        ../helpers/
        src/
)

set_target_properties(10_PITF_main_objectSlicing PROPERTIES SUFFIX ".out")