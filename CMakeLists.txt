
project(taggsystem)
cmake_minimum_required(VERSION 3.20)

add_library(
    taggsystem
    taggsystem/users.cpp
)

enable_testing()

add_subdirectory(test)

