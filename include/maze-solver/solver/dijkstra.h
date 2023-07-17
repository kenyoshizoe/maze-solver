#ifndef MAZE_SOLVER_SOLVER_DIJKSTRA_H_
#define MAZE_SOLVER_SOLVER_DIJKSTRA_H_

#include "maze-solver/geometry.h"
#include "maze-solver/solver/solver_base.h"

namespace maze_solver {
class Dijkstra : public SolverBase {
 public:
  Dijkstra() {}
  ~Dijkstra() {}
  /**
   * @brief Solve the maze.
   *
   * @param maze
   * @return Path The path from start to goal.
   */
  Path Solve(Maze maze) override;

 private:
  struct Node {
    Path path;
    int cumulative_cost;
  };
};
}  // namespace maze_solver

#endif  // MAZE_SOLVER_SOLVER_DIJKSTRA_H_
