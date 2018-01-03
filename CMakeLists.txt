cmake_minimum_required(VERSION 3.9)
project(FMPML)

set(CMAKE_CXX_STANDARD 11)

add_library(FMPML SHARED library.cpp library.h)