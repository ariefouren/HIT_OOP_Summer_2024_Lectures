# Specify the minimum version for CMake
cmake_minimum_required(VERSION 3.10)

# Project's name
project(TimeTest)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 14)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(TimeTest TimeTest.cpp Time.cpp)

# Specify include directories
target_include_directories(TimeTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})