#ifndef MAZE_SOLVER_SOLVER_DSF_H_
#define MAZE_SOLVER_SOLVER_DSF_H_

#include "maze-solver/geometry.h"
#include "maze-solver/solver/solver_base.h"

namespace maze_solver {
class DFS : public SolverBase {
 public:
  DFS() {}
  ~DFS() {}
  Path Solve(Maze maze) override;
};
}  // namespace maze_solver

#endif  // MAZE_SOLVER_SOLVER_DSF_H_
