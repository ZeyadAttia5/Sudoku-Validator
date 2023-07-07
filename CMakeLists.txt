cmake_minimum_required(VERSION 3.25)
project(SudokoValidator C)

set(CMAKE_C_STANDARD 11)

add_executable(SudokoValidator main.c workerThreads.c workerThreads.h sudoku.h)
