add_subdirectory(utils/)

add_executable(meshimator main.cc)
target_link_libraries(meshimator
    PRIVATE utils)

target_include_directories(meshimator
    PUBLIC ${CMAKE_SOURCE_DIR}/include/utils)

add_custom_command(TARGET meshimator
    POST_BUILD
    COMMAND cp meshimator ..)
