cmake_minimum_required(VERSION 3.13)
project(04_UDEF)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(04_UDEF
        src/main_04_UDEF_e.cpp
        src/RationalNumber.cpp)

include_directories(
        ../helpers/
        src
)

#set_target_properties(04_UDEF PROPERTIES PREFIX "solved_")
set_target_properties(04_UDEF PROPERTIES SUFFIX ".out")
