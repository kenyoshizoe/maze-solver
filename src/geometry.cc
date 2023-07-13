#include "maze-solver/geometry.h"

#include <iostream>

namespace maze_solver {
Path::Path(Position point) : position_(point) {
  // initialize visited
  for (int y = 0; y < 16; y++)
    for (int x = 0; x < 16; x++) visited_[y][x] = false;
  visited_[point.y][point.x] = true;
}
Path::Path(Position position, std::vector<Direction> directions,
           std::array<std::array<bool, 16>, 16> visited, Direction direction)
    : directions_(directions), visited_(visited) {
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
  position_ = position;
  directions_.push_back(direction);
  visited_[position_.y][position_.x] = true;
}
Path Path::GetNextPath(Direction direction) const {
  return Path(this->position_, this->directions_, this->visited_, direction);
}
std::vector<Path> Path::GetNextPaths(Maze maze) const {
  std::vector<Path> next_paths;
  for (auto direction : maze.GetAvailableDirection(position_)) {
    Position next_position = position_;
    switch (direction) {
      case Direction::kEast:
        next_position.x++;
        break;
      case Direction::kNorth:
        next_position.y--;
        break;
      case Direction::kSouth:
        next_position.y++;
        break;
      case Direction::kWest:
        next_position.x--;
        break;
      default:
        break;
    }

    if (visited_[next_position.y][next_position.x]) {
      continue;
    }
    next_paths.push_back(GetNextPath(direction));
  }
  return next_paths;
}
}  // namespace maze_solver
