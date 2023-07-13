#ifndef MAZE_SOLVER_SOLVER_BREADTH_FIRST_H_
#define MAZE_SOLVER_SOLVER_BREADTH_FIRST_H_

#include <memory>

#include "maze-solver/geometry.h"
#include "maze-solver/solver/solver_base.h"
#include "maze-solver/visualizer/print.h"

namespace maze_solver {
class BFS : public SolverBase {
 public:
  BFS(/* args */) {}
  ~BFS() {}
  Path Solve(Maze maze) override;
};
}  // namespace maze_solver
#endif  // MAZE_SOLVER_SOLVER_BREADTH_FIRST_H_
