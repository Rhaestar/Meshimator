add_library(utils STATIC
    vector4.cc
    triangle.cc
    tiny_obj_loader.cc)

target_include_directories(utils
    PUBLIC ${CMAKE_SOURCE_DIR}/include/utils)
