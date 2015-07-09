cmake_minimum_required(VERSION 3.1)
project(mvm)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")

set(SOURCE_FILES test.c)
add_executable(mvm ${SOURCE_FILES} mvm.h mvm.c)