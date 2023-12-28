cmake_minimum_required(VERSION 3.25)
project(lg)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE debug)

include_directories(..)

add_executable(lg
	main.cpp
	../lg.h
)
