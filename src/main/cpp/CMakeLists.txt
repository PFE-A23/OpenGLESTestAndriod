cmake_minimum_required(VERSION 3.22.1)

project("opengltest_android")

add_library(opengltest_android SHARED native-lib.cpp)

find_library(GL_LIB GLESv2)

target_link_libraries(opengltest_android android log ${GL_LIB})
