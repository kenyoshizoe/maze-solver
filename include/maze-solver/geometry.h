#ifndef MAZE_SOLVER_GEOMETRY_H_
#define MAZE_SOLVER_GEOMETRY_H_

#include <memory>
#include <utility>
#include <vector>

namespace maze_solver {
enum class Direction {
  kNone = 0b0000,
  kNorth = 0b1000,
  kNorthEast = 0b1010,
  kEast = 0b0010,
  kSouthEast = 0b0011,
  kSouth = 0b0001,
  kSouthWest = 0b0101,
  kWest = 0b0100,
  kNorthWest = 0b1100,
};

struct Position {
  int x;
  int y;
};

struct Pose {
  Position position;
  Direction machine_direction;
};

class Maze {
 public:
  Maze(std::array<std::array<int, 16>, 16> wall, Position start, Position goal)
      : wall_(wall), start_(start), goal_(goal){};
  std::array<std::array<int, 16>, 16> GetWall() const { return wall_; }
  Position GetStart() const { return start_; }
  Position GetGoal() const { return goal_; }
  std::vector<Direction> GetAvailableDirection(Position position) const {
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
      available.push_back(direction);
    }
    return available;
  }

 private:
  /**
   * @brief 2次元配列で迷路の壁を表現する。
   * 1bit: West Wall
   * 2bit: North Wall
   * 3bit: South Wall
   * 4bit: East Wall
   */
  std::array<std::array<int, 16>, 16> wall_;
  Position start_;
  Position goal_;
};

class Path : public std::enable_shared_from_this<Path> {
 public:
  /**
   * @brief Constructor for Start Point
   * @param point
   */
  Path(Position point);
  /**
   * @brief Constructor for Next Point
   * @param path
   * @param direction
   */
  Path(Position position, std::vector<Direction> directions,
       std::array<std::array<bool, 16>, 16> visited, Direction direction);
  Position GetPosition() const { return position_; };
  std::vector<Direction> GetDirections() const { return directions_; };
  std::array<std::array<bool, 16>, 16> GetVisited() const { return visited_; };

  Path GetNextPath(Direction direction) const;
  std::vector<Path> GetNextPaths(Maze maze) const;

 private:
  Position position_;
  std::vector<Direction> directions_;
  std::array<std::array<bool, 16>, 16> visited_;
};

}  // namespace maze_solver

#endif  // MAZE_SOLVER_GEOMETRY_H_
