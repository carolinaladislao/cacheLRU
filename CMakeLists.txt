cmake_minimum_required(VERSION 3.27)
project(cacheLRU C)

set(CMAKE_C_STANDARD 11)

add_executable(cacheLRU main.c
        cache.c
        cache.h)
