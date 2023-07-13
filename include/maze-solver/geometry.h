#ifndef MAZE_SOLVER_GEOMETRY_H_
#define MAZE_SOLVER_GEOMETRY_H_

#include <memory>
#include <utility>
#include <vector>

namespace maze_solver {
enum class Direction {
  kWest = 0b0001,
  kNorth = 0b0010,
  kEast = 0b0100,
  kSouth = 0b1000,
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
  /**
   * @brief 2次元配列で表現された迷路の壁の情報を返す。
   * 1bit: South Wall
   * 2bit: East Wall
   * 3bit: West Wall
   * 4bit: North Wall
   */
  std::array<std::array<int, 16>, 16> GetWall() const { return wall_; }
  Position GetStart() const { return start_; }
  Position GetGoal() const { return goal_; }
  std::vector<Direction> GetAvailableDirection(Position position) const {
    std::vector<Direction> available;
    if (!(wall_[position.y][position.x] & 0b0001)) {
      available.push_back(Direction::kNorth);
    }
    if (!(wall_[position.y][position.x] & 0b0010)) {
      available.push_back(Direction::kWest);
    }
    if (!(wall_[position.y][position.x] & 0b0100)) {
      available.push_back(Direction::kEast);
    }
    if (!(wall_[position.y][position.x] & 0b1000)) {
      available.push_back(Direction::kSouth);
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

  std::shared_ptr<Path> GetNextPath(Direction direction) const;
  std::vector<std::shared_ptr<Path>> GetNextPaths(
      const std::shared_ptr<Maze> maze) const;

 private:
  Position position_;
  std::vector<Direction> directions_;
  std::array<std::array<bool, 16>, 16> visited_;
};

}  // namespace maze_solver

#endif  // MAZE_SOLVER_GEOMETRY_H_
