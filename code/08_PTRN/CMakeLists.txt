cmake_minimum_required(VERSION 3.13)

project(08_PTRN_main)
project(08_SIMULATION)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra") # -Werror
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(08_PTRN_main
        src/base/main.cpp
        src/base/VehicleFactory.cpp
        src/base/Truck.cpp
        src/base/Car.cpp
        src/base/Logger.cpp
        src/base/Vehicle.cpp
        )

add_executable(08_SIMULATION
        src/simulation/Simulation.cpp
        src/simulation/main.cpp
        src/simulation/Human.cpp
        src/simulation/Bank.cpp
        src/simulation/headers.h)

include_directories(
        ../helpers/
        src/simulation/
)

set_target_properties(08_PTRN_main PROPERTIES SUFFIX ".out")
set_target_properties(08_SIMULATION PROPERTIES SUFFIX ".out")
