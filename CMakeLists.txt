cmake_minimum_required(VERSION 3.23)
project(maze_solver CXX)

file(GLOB_RECURSE SRC ${CMAKE_CURRENT_SOURCE_DIR} src/*.cc)
message("SRC:${SRC}")
add_library(maze_solver ${SRC})
target_include_directories(maze_solver
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(bfs_test
    test/bfs_test.cc
)
target_link_libraries(bfs_test
    PRIVATE
    maze_solver
)
target_include_directories(bfs_test
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
add_executable(dfs_test
    test/dfs_test.cc
)
target_link_libraries(dfs_test
    PRIVATE
    maze_solver
)
target_include_directories(dfs_test
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
add_executable(dijkstra_test
    test/dijkstra_test.cc
)
target_link_libraries(dijkstra_test
    PRIVATE
    maze_solver
)
target_include_directories(dijkstra_test
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
