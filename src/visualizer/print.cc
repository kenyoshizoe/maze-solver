#include <iostream>
#include <string>

#include "maze-solver/geometry.h"

namespace maze_solver {
void PrintMaze(Maze maze, Path path) {
  // create path map
  std::array<std::array<Direction, 16>, 16> path_map;
  // initialize
  for (int y = 0; y < 16; y++) {
    for (int x = 0; x < 16; x++) {
      path_map[y][x] = Direction::kNone;
    }
  }
  Position position = maze.GetStart();
  for (auto direction : path.GetDirections()) {
    path_map[position.y][position.x] = direction;
    switch (direction) {
      case Direction::kNorth:
        position.y--;
        break;
      case Direction::kEast:
        position.x++;
        break;
      case Direction::kWest:
        position.x--;
        break;
      case Direction::kSouth:
        position.y++;
        break;
    }
  }
  std::cout << std::endl;

  std::string str = "";
  str +=
      "┌────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬─"
      "───┬────┐\n";
  for (int y = 0; y < 16; y++) {
    for (int x = 0; x < 16; x++) {
      if (maze.GetWall()[y][x] & static_cast<int>(Direction::kWest)) {
        str += "│";
      } else {
        str += " ";
      }
      str += " ";
      // TODO: 経路の描画
      if (maze.GetGoal().x == x && maze.GetGoal().y == y) {
        str += "🚩";
      } else if (maze.GetStart().x == x && maze.GetStart().y == y) {
        str += "⭐";
      } else if (path_map[y][x] == Direction::kNorth) {
        str += "↑ ";
      } else if (path_map[y][x] == Direction::kNorthEast) {
        str += "↗ ";
      } else if (path_map[y][x] == Direction::kEast) {
        str += "→ ";
      } else if (path_map[y][x] == Direction::kSouthEast) {
        str += "↘ ";
      } else if (path_map[y][x] == Direction::kSouth) {
        str += "↓ ";
      } else if (path_map[y][x] == Direction::kSouthWest) {
        str += "↙ ";
      } else if (path_map[y][x] == Direction::kWest) {
        str += "← ";
      } else if (path_map[y][x] == Direction::kNorthWest) {
        str += "↖ ";
      } else {
        str += "  ";
      }
      str += " ";
    }
    str += "│";
    str += "\n";

    if (y == 15) {
      break;
    }

    str += "├";
    for (int x = 0; x < 16; x++) {
      if (maze.GetWall()[y][x] & static_cast<int>(Direction::kSouth)) {
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
