#ifndef MAZE_SOLVER_SOLVER_ASTAR_H_
#define MAZE_SOLVER_SOLVER_ASTAR_H_

#include "maze-solver/geometry.h"
#include "maze-solver/solver/solver_base.h"

namespace maze_solver {
class Astar : public SolverBase {
 public:
  Astar() {}
  ~Astar() {}
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
    int heuristic_cost;
  };
  int CalcHeuristicCost(const Path& path, const Maze& maze) const;
};
}  // namespace maze_solver

#endif  // MAZE_SOLVER_SOLVER_ASTAR_H_
