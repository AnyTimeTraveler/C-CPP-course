cmake_minimum_required(VERSION 3.13)

project(08_PTRN_main)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(08_PTRN_main
			src/main.cpp
			src/VehicleFactory.cpp
			src/Truck.cpp
			src/Car.cpp
			src/VehicleFactory.hpp
			src/Logger.cpp
			src/Vehicle.cpp
			src/Vehicle.hpp
			src/Logger.hpp
			src/Truck.hpp
			src/Car.hpp
)

include_directories(
        ../helpers/
        src/
)

set_target_properties(08_PTRN_main PROPERTIES SUFFIX ".out")