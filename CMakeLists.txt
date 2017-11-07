cmake_minimum_required(VERSION 3.8)
project(sampleHw6)

set(CMAKE_CXX_STANDARD 11)

#set(SOURCE_FILES main.cpp)
set(SOURCE_FILES testArray.cpp SuperArray.cpp SuperArray.h)

add_executable(sampleHw6 ${SOURCE_FILES})