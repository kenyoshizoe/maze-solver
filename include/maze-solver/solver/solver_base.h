#ifndef MAZE_SOLVER_SOLVER_SOLVER_BASE_H_
#define MAZE_SOLVER_SOLVER_SOLVER_BASE_H_

#include <utility>
#include <vector>

#include "maze-solver/geometry/maze.h"

namespace maze_solver {
class SolverBase {
 public:
  /**
   * @brief Solve the maze.
   *
   * @param maze
   * @return std::vector<std::pair<int, int>> The path from start to goal.
   */
  virtual std::vector<std::pair<int, int>> Solve(Maze maze) = 0;
};
}  // namespace maze_solver

#endif  // MAZE_SOLVER_SOLVER_SOLVER_BASE_H_
