#!/bin/bash
clang++ -std=c++14 -o shape_main.out -I ../helpers/ shapes_main.cpp ../helpers/AnsiConsole.cpp 
clang++ -std=c++14 -o ansiConsole.out -I ../helpers/ AnsiConsoleDemo.cpp ../helpers/AnsiConsole.cpp
