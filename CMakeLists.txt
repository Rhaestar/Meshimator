cmake_minimum_required (VERSION 3.3)

project(Meshimator
    VERSION 1.0
    LANGUAGES CXX)

add_compile_options(-Wall -Wextra -Werror -std=c++17 -g -pedantic -Ofast)

add_subdirectory(src/)
