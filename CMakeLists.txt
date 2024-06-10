cmake_minimum_required(VERSION 3.26)
project(Lab_5 C)

set(CMAKE_C_STANDARD 17)

add_executable(Lab_5 main.c
        CPU.c
        CPU.h
        mem.c
        mem.h
)
