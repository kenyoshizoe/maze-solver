#include "maze-solver/geometry.h"

namespace maze_solver {
Path::Path(std::pair<int, int> point) : position_(point) {
  visited_[point.second][point.first] = true;
}
Path::Path(std::pair<int, int> position, std::vector<Direction> directions,
           std::array<std::array<bool, 16>, 16> visited, Direction direction)
    : directions_(directions), visited_(visited) {
  switch (direction) {
    case Direction::kNorth:
      position.second--;
      break;
    case Direction::kEast:
      position.first++;
      break;
    case Direction::kWest:
      position.first--;
      break;
    case Direction::kSouth:
      position.second++;
      break;
  }
  position_ = position;
  directions_.push_back(direction);
  visited_[position_.second][position_.first] = true;
}
std::shared_ptr<Path> Path::GetNextPath(Direction direction) const {
  return std::make_shared<Path>(this->position_, this->directions_,
                                this->visited_, direction);
}
std::vector<std::shared_ptr<Path>> Path::GetNextPaths(
    const std::shared_ptr<Maze> maze) const {
  std::vector<std::shared_ptr<Path>> next_paths;
  for (auto direction : maze->GetAvailableDirection(position_)) {
    next_paths.push_back(GetNextPath(direction));
  }
  return next_paths;
}
}  // namespace maze_solver
