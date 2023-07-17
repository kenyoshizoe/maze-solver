#ifndef MAZE_SOLVER_GEOMETRY_H_
#define MAZE_SOLVER_GEOMETRY_H_

#include <iostream>
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

int DirectionToInt(Direction direction);

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
   * @brief 迷路の壁情報を返す
   * @return std::array<std::array<int, 16>, 16> 
   */
  std::array<std::array<int, 16>, 16> GetWall() const { return wall_; }
  /**
   * @brief スタートの座標を返す
   * @return Position 
   */
  Position GetStart() const { return start_; }
  /**
   * @brief ゴールの座標を返す
   * @return Position 
   */
  Position GetGoal() const { return goal_; }
  /**
   * @brief ある座標から進める方向を返す
   * @param position
   * @return std::vector<Direction>
   */
  std::vector<Direction> GetAvailableDirection(Position position) const;

 private:
  /**
   * @brief 2次元配列で迷路の壁を表現する。
   * @details
   * 1bit: South Wall
   * 2bit: East Wall
   * 3bit: West Wall
   * 4bit: North Wall
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
