#include "maze-solver/geometry.h"
#include <iostream>

namespace maze_solver {
Path::Path(Position point) : position_(point) {
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
    next_paths.push_back(GetNextPath(direction));
  }
  return next_paths;
}
}  // namespace maze_solver
