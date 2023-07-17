#include "maze-solver/solver/dfs.h"

#include <array>
#include <chrono>

#include "maze-solver/geometry.h"
#include "maze-solver/visualizer/print.h"

int main() {
  // 左下が(0,0)で、[x][y]で指定する
  std::array<std::array<int, 16>, 16> wall_input = {
      {{6, 4, 4, 6, 6, 6, 7, 13, 13, 13, 12, 6, 6, 6, 4, 5},
       {4, 1, 10, 4, 5, 13, 12, 0, 0, 0, 0, 4, 6, 6, 3, 9},
       {1, 8, 5, 11, 11, 8, 3, 11, 11, 9, 11, 11, 12, 6, 5, 9},
       {1, 11, 10, 5, 12, 2, 6, 6, 5, 9, 12, 6, 1, 12, 1, 9},
       {0, 6, 6, 2, 2, 4, 6, 6, 3, 10, 3, 13, 11, 9, 9, 9},
       {0, 6, 7, 12, 6, 3, 12, 6, 4, 5, 14, 2, 6, 3, 11, 9},
       {0, 6, 4, 2, 7, 12, 0, 6, 3, 8, 5, 12, 6, 4, 6, 1},
       {0, 5, 10, 6, 7, 9, 10, 4, 5, 9, 9, 8, 4, 2, 4, 1},
       {1, 10, 6, 6, 5, 10, 5, 10, 3, 9, 9, 9, 10, 4, 3, 9},
       {0, 6, 7, 12, 3, 14, 2, 5, 14, 2, 1, 10, 5, 10, 5, 9},
       {1, 12, 5, 10, 6, 5, 14, 2, 5, 12, 2, 5, 10, 4, 3, 9},
       {0, 3, 10, 4, 6, 2, 5, 14, 2, 0, 6, 2, 4, 1, 14, 1},
       {0, 5, 12, 2, 5, 14, 2, 5, 14, 2, 4, 6, 1, 9, 14, 1},
       {1, 8, 3, 14, 1, 13, 12, 3, 13, 13, 10, 5, 10, 0, 6, 1},
       {0, 1, 13, 13, 9, 9, 10, 5, 8, 2, 5, 10, 6, 2, 6, 1},
       {1, 10, 2, 2, 2, 2, 6, 2, 3, 15, 10, 6, 6, 6, 6, 3}}};
  // 右上が(0,0)で、[y][x]で指定するように変換
  std::array<std::array<int, 16>, 16> wall;
  for (int y = 0; y < 16; y++) {
    for (int x = 0; x < 16; x++) {
      wall[y][x] = wall_input[x][y];
    }
  }
  maze_solver::Maze maze(wall, {0, 0}, {8, 8});
  maze_solver::DFS solver;
  solver.SetPrintSolvingPerfomance(true);
  maze_solver::Path path = solver.Solve(maze);
  maze_solver::PrintMaze(maze, path);
  return 0;
}
