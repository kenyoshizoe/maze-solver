cmake_minimum_required(VERSION 3.25)
project(maze_solver CXX)

add_library(maze_solver
    src/solver/breadth_first.cc
)
target_include_directories(maze_solver
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(maze_solver_test
    test/maze_solver_test.cc
)
target_link_libraries(maze_solver_test
    PRIVATE
        maze_solver
)
target_include_directories(maze_solver_test
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
