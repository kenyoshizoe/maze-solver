#ifndef MAZE_SOLVER_SOLVER_SOLVER_BASE_H_
#define MAZE_SOLVER_SOLVER_SOLVER_BASE_H_

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
};
}  // namespace maze_solver

#endif  // MAZE_SOLVER_SOLVER_SOLVER_BASE_H_
