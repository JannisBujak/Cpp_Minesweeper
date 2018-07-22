cmake_minimum_required(VERSION 3.10)
project(Minesweeper)

set(CMAKE_CXX_STANDARD 17)

add_executable(Minesweeper main.cpp src/Field.cpp src/Field.h src/Game.cpp src/Game.h)