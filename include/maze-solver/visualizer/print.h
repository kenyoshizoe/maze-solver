#ifndef MAZE_SOLVER_VISUALIZER_PRINT_H_
#define MAZE_SOLVER_VISUALIZER_PRINT_H_

#include <iostream>
#include <string>

#include "maze-solver/geometry/maze.h"

namespace maze_solver {
void PrintMaze(Maze maze, std::vector<std::pair<int, int>> path) {
  std::string str = "";
  str +=
      "┌────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬─"
      "───┬────┐\n";
  for (int y = 0; y < 16; y++) {
    str += "│";
    for (int x = 0; x < 16; x++) {
      str += " ";

      if (maze.GetGoal().first == x && maze.GetGoal().second == y) {
        str += "🚩";
      } else if (maze.GetStart().first == x && maze.GetStart().second == y) {
        str += "⭐";
      } else if (false /**/) {
        str += "👈";
      } else {
        str += "  ";
      }
      // TODO: 経路の描画
      str += " ";
      if (maze.GetWall()[y][x] & 0b0001) {
        str += "│";
      } else {
        str += " ";
      }
    }
    str += "\n";

    if (y == 15) {
      break;
    }

    str += "├";
    for (int x = 0; x < 16; x++) {
      if (maze.GetWall()[y][x] & 0b0010) {
        str += "────";
      } else {
        str += "    ";
      }
      str += x == 15 ? "┤" : "┼";
    }
    str += "\n";
  }

  str +=
      "└────┴────┴────┴────┴────┴────┴────┴────┴────┴────┴────┴────┴────┴────┴─"
      "───┴────┘";
  std::cout << str << std::endl;
}
}  // namespace maze_solver
#endif  // MAZE_SOLVER_VISUALIZER_PRINT_H_
