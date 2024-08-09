# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(RectangleTest)

set(CMAKE_CXX_STANDARD 14)

add_executable(RectangleTest RectangleTest.cpp Point.cpp Rectangle.cpp)