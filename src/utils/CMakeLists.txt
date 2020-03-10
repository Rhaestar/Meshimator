add_library(utils STATIC
    vector3.cc
    triangle.cc)

target_include_directories(utils
    PUBLIC ${CMAKE_SOURCE_DIR}/include/utils)
