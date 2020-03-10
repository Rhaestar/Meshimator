cmake_minimum_required (VERSION 3.3)

project(Meshimator
    VERSION 1.0
    LANGUAGES CXX)

#add vectoriise
add_compile_options(-Wall -Wextra -Werror -std=c++17 -O3 -pedantic -fopenmp)

add_subdirectory(src/)
