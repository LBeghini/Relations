cmake_minimum_required(VERSION 3.16)
project(relations C)

set(CMAKE_C_STANDARD 99)

add_executable(relations src/main.c src/fileIO.c src/fileIO.h src/set.c src/set.h src/global.h src/operations.c src/operations.h src/validation.c src/validation.h)