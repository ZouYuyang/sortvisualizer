cmake_minimum_required(VERSION 3.21)
project(sort C)

set(CMAKE_C_STANDARD 99)

add_library(sortlib sortVisualizer.c sortVisualizer.h)
add_executable(sort main.c)
target_link_libraries(sort sortlib)