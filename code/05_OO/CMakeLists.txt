cmake_minimum_required(VERSION 3.13)
project(05_OO_shapes)
project(05_OO_ansi)
project(05_OO_main_a)
project(05_OO_main_b)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fno-elide-constructors")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(05_OO_shapes
        src/shapes_main.cpp
        ../helpers/AnsiConsole.cpp)

add_executable(05_OO_ansi
        src/AnsiConsoleDemo.cpp
        ../helpers/AnsiConsole.cpp)

add_executable(05_OO_main_a
        src/main_mp4_OO_a_vehicles.cpp
        ../helpers/AnsiConsole.cpp)

add_executable(05_OO_main_b
        src/main_mp4_OO_b.cpp
        ../helpers/AnsiConsole.cpp)

include_directories(
        ../helpers/
        src/
)

set_target_properties(05_OO_shapes PROPERTIES SUFFIX ".out")
set_target_properties(05_OO_ansi PROPERTIES SUFFIX ".out")
set_target_properties(05_OO_main_a PROPERTIES SUFFIX ".out")
set_target_properties(05_OO_main_b PROPERTIES SUFFIX ".out")
