#include "maze-solver/geometry.h"

#include <iostream>

namespace maze_solver {
int DirectionToInt(Direction direction) {
  switch (direction) {
    case Direction::kNorth:
      return 0;
    case Direction::kNorthEast:
      return 1;
    case Direction::kEast:
      return 2;
    case Direction::kSouthEast:
      return 3;
    case Direction::kSouth:
      return 4;
    case Direction::kSouthWest:
      return 5;
    case Direction::kWest:
      return 6;
    case Direction::kNorthWest:
      return 7;
    default:
      return -1;
  }
}

std::vector<Direction> Maze::GetAvailableDirection(Position position) const {
  std::vector<Direction> available;
  for (auto direction :
       {Direction::kNorth, Direction::kNorthEast, Direction::kEast,
        Direction::kSouthEast, Direction::kSouth, Direction::kSouthWest,
        Direction::kWest, Direction::kNorthWest}) {
    // Wall Check
    if (wall_[position.y][position.x] & static_cast<int>(direction)) continue;
    // Boundary Check
    if (static_cast<int>(direction) & static_cast<int>(Direction::kNorth) &&
        position.y == 0) {
      continue;
    }
    if (static_cast<int>(direction) & static_cast<int>(Direction::kEast) &&
        position.x == 15) {
      continue;
    }
    if (static_cast<int>(direction) & static_cast<int>(Direction::kSouth) &&
        position.y == 15) {
      continue;
    }
    if (static_cast<int>(direction) & static_cast<int>(Direction::kWest) &&
        position.x == 0) {
      continue;
    }
    // Diagonal Wall Check
    if (direction == Direction::kNorthEast &&
        (wall_[position.y - 1][position.x + 1] &
             static_cast<int>(Direction::kSouth) ||
         wall_[position.y - 1][position.x + 1] &
             static_cast<int>(Direction::kWest)))
      continue;
    if (direction == Direction::kSouthEast &&
        (wall_[position.y + 1][position.x + 1] &
             static_cast<int>(Direction::kNorth) ||
         wall_[position.y + 1][position.x + 1] &
             static_cast<int>(Direction::kWest)))
      continue;
    if (direction == Direction::kSouthWest &&
        (wall_[position.y + 1][position.x - 1] &
             static_cast<int>(Direction::kNorth) ||
         wall_[position.y + 1][position.x - 1] &
             static_cast<int>(Direction::kEast)))
      continue;
    if (direction == Direction::kNorthWest &&
        (wall_[position.y - 1][position.x - 1] &
             static_cast<int>(Direction::kSouth) ||
         wall_[position.y - 1][position.x - 1] &
             static_cast<int>(Direction::kEast)))
      continue;
    available.push_back(direction);
  }
  return available;
}

Path::Path(Position point) : position_(point) {
  // initialize visited
  for (int y = 0; y < 16; y++)
    for (int x = 0; x < 16; x++) visited_[y][x] = false;
  visited_[point.y][point.x] = true;
}
Path::Path(Position position, std::vector<Direction> directions,
           std::array<std::array<bool, 16>, 16> visited, Direction direction)
    : directions_(directions), visited_(visited) {
  if (static_cast<int>(direction) & static_cast<int>(Direction::kNorth)) {
    position.y--;
  }
  if (static_cast<int>(direction) & static_cast<int>(Direction::kEast)) {
    position.x++;
  }
  if (static_cast<int>(direction) & static_cast<int>(Direction::kWest)) {
    position.x--;
  }
  if (static_cast<int>(direction) & static_cast<int>(Direction::kSouth)) {
    position.y++;
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
    Path next_path = GetNextPath(direction);
    if (visited_[next_path.GetPosition().y][next_path.GetPosition().x]) {
      continue;
    }
    next_paths.push_back(GetNextPath(direction));
  }
  return next_paths;
}
}  // namespace maze_solver
