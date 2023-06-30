#ifndef MAZE_SOLVER_GEOMETRY_MAZE_H_
#define MAZE_SOLVER_GEOMETRY_MAZE_H_

#include <array>
#include <utility>
#include <vector>

namespace maze_solver {
class Maze {
 public:
  Maze(std::array<std::array<int, 16>, 16> wall, std::pair<int, int> start,
       std::pair<int, int> goal)
      : wall_(wall), start_(start), goal_(goal){};
  /**
   * @brief 2次元配列で表現された迷路の壁の情報を返す。
   * 1bit: South Wall
   * 2bit: East Wall
   * 3bit: West Wall
   * 4bit: North Wall
   */
  std::array<std::array<int, 16>, 16> GetWall() const { return wall_; }
  std::pair<int, int> GetStart() const { return start_; }
  std::pair<int, int> GetGoal() const { return goal_; }
  std::vector<std::pair<int, int>> GetAvailable(std::pair<int, int> position) {
    std::vector<std::pair<int, int>> available;
    if (!(wall_[position.second][position.first] & 0b0001)) {
      available.push_back(std::make_pair(position.first, position.second - 1));
    }
    if (!(wall_[position.second][position.first] & 0b0010)) {
      available.push_back(std::make_pair(position.first - 1, position.second));
    }
    if (!(wall_[position.second][position.first] & 0b0100)) {
      available.push_back(std::make_pair(position.first + 1, position.second));
    }
    if (!(wall_[position.second][position.first] & 0b1000)) {
      available.push_back(std::make_pair(position.first, position.second + 1));
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
  std::pair<int, int> start_;
  std::pair<int, int> goal_;
};
}  // namespace maze_solver

#endif  // MAZE_SOLVER_GEOMETRY_MAZE_H_
