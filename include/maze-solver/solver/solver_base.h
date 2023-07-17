#ifndef MAZE_SOLVER_SOLVER_SOLVER_BASE_H_
#define MAZE_SOLVER_SOLVER_SOLVER_BASE_H_

#include <chrono>
#include <utility>
#include <vector>

#include "maze-solver/geometry.h"

namespace maze_solver {
class SolverBase {
 public:
  /**
   * @brief Solve the maze.
   *
   * @param maze
   * @return Path The path from start to goal.
   */
  virtual Path Solve(Maze maze) = 0;
  void SetPrintSolvingProcess(bool print_solving_process) {
    print_solving_process_ = print_solving_process;
  }
  void SetPrintSolvingPerfomance(bool print_solving_perfomance) {
    print_solving_perfomance_ = print_solving_perfomance;
  }

 protected:
  int CalcCost(const Path& path) const {
    Direction pre_direction = Direction::kNone;
    int cost = 0;
    for (auto direction : path.GetDirections()) {
      if (pre_direction == Direction::kNone) {
        pre_direction = direction;
        continue;
      }
      int rotate_cost =
          std::abs(DirectionToInt(pre_direction) - DirectionToInt(direction)) %
          4;
      int acc_cost = rotate_cost == 0 ? 0 : 3;
      cost += 1 + rotate_cost + acc_cost;
      pre_direction = direction;
    }
    return cost;
  }
  void PrintSolvingPerfomance(
      const Path& path, const int order_count,
      const std::chrono::system_clock::time_point start_time,
      int max_container_size) const {
    std::cout << "cost(l1):" << path.GetDirections().size()
              << ", cost:" << CalcCost(path) << ", order_count:" << order_count
              << ", processing time:"
              << std::chrono::duration_cast<std::chrono::milliseconds>(
                     std::chrono::system_clock::now() - start_time)
                     .count()
              << "[ms], max_container_size:" << max_container_size << std::endl;
  }
  bool print_solving_process_ = false;
  bool print_solving_perfomance_ = false;
};
}  // namespace maze_solver

#endif  // MAZE_SOLVER_SOLVER_SOLVER_BASE_H_
