cmake_minimum_required(VERSION 3.23)
project(maze_solver CXX)

file(GLOB_RECURSE SRC ${CMAKE_CURRENT_SOURCE_DIR} src/*.cc)
message("SRC:${SRC}")
add_library(maze_solver ${SRC})
target_include_directories(maze_solver
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(breadth_first_test
    test/breadth_first_test.cc
)
target_link_libraries(breadth_first_test
    PRIVATE
    maze_solver
)
target_include_directories(breadth_first_test
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
