#ifndef MAZE_SOLVER_SOLVER_BREADTH_FIRST_H_
#define MAZE_SOLVER_SOLVER_BREADTH_FIRST_H_

#include <memory>

#include "maze-solver/solver/solver_base.h"

namespace maze_solver {
class BreadthFirst : public SolverBase {
 public:
  BreadthFirst(/* args */) {}
  ~BreadthFirst() {}
  std::vector<std::pair<int, int>> Solve(Maze maze) override;

 private:
  struct Node {
    std::pair<int, int> position_;
    std::shared_ptr<Node> parent_;
  };
};
}  // namespace maze_solver
#endif  // MAZE_SOLVER_SOLVER_BREADTH_FIRST_H_
