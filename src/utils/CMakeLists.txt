add_library(utils STATIC
    vector4.cc
    triangle.cc
    symmat.cc
    vertex.cc
    vertexpair.cc
    heap.cc)

target_include_directories(utils
    PUBLIC ${CMAKE_SOURCE_DIR}/include/utils)
