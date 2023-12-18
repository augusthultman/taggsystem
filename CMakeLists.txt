
project(taggsystem)
cmake_minimum_required(VERSION 3.20)

add_library(
    taggsystem
    taggsystem/users.cpp
)

add_subdirectory(test)

enable_testing()
