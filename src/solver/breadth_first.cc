#include "maze-solver/solver/breadth_first.h"

#include <algorithm>
#include <iostream>
#include <queue>

namespace maze_solver {
std::vector<std::pair<int, int>> BreadthFirst::Solve(Maze maze) {
  std::queue<Node> open;

  Node start = {maze.GetStart(), nullptr};
  open.push(start);

  while (true) {
    if (open.empty()) {
      return std::vector<std::pair<int, int>>();
    }

    Node n = open.front();
    open.pop();

    if (n.position_ == maze.GetGoal()) {
      std::vector<std::pair<int, int>> path;
      while (n.parent_ != nullptr) {
        path.push_back(n.position_);
        n = *n.parent_;
      }
      std::reverse(path.begin(), path.end());
      return path;
    }

    std::vector<std::pair<int, int>> available = maze.GetAvailable(n.position_);
    for (auto a : available) {
      Node next = {a, std::make_shared<Node>(n)};
      open.push(next);
    }

    std::cout << open.size() << std::endl;
  }

  std::vector<std::pair<int, int>> path;
  return path;
}
}  // namespace maze_solver
