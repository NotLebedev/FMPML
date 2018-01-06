cmake_minimum_required(VERSION 3.9)
project(FMPML)

set(CMAKE_CXX_STANDARD 11)

add_library(FMPML SHARED library.cpp library.h UniversalModuleInterface.h)

configure_file(${CMAKE_CURRENT_BINARY_DIR}/cygFMPML.dll D:/endearing/Work/CoffeMachine/Modules/FMPML/FMPML.dll COPYONLY)
configure_file(${CMAKE_CURRENT_BINARY_DIR}/cygFMPML.dll D:/endearing/Work/CoffeMachine/cmake-build-debug/Modules/FMPML/FMPML.dll COPYONLY)
