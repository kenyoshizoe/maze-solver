#ifndef MAZE_SOLVER_SOLVER_BREADTH_FIRST_H_
#define MAZE_SOLVER_SOLVER_BREADTH_FIRST_H_

#include <memory>

#include "maze-solver/geometry.h"
#include "maze-solver/solver/solver_base.h"
#include "maze-solver/visualizer/print.h"

namespace maze_solver {
class BreadthFirst : public SolverBase {
 public:
  BreadthFirst(/* args */) {}
  ~BreadthFirst() {}
  Path Solve(Maze maze) override;

 private:
};
}  // namespace maze_solver
#endif  // MAZE_SOLVER_SOLVER_BREADTH_FIRST_H_
