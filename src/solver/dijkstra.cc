#include "maze-solver/solver/dijkstra.h"

#include <cmath>
#include <iostream>
#include <queue>
#include <thread>

#include "maze-solver/visualizer/print.h"

namespace maze_solver {
Path Dijkstra::Solve(Maze maze) {
  auto compare = [](const Node& lhs, const Node& rhs) {
    return lhs.cumulative_cost > rhs.cumulative_cost;
  };
  std::priority_queue<Node, std::vector<Node>, decltype(compare)> open{compare};
  Path start(maze.GetStart());
  open.push({start, 0});
  while (true) {
    if (open.empty()) {
      return Path(maze.GetStart());
    }
    Node n = open.top();
    open.pop();
    if (n.path.GetPosition().x == maze.GetGoal().x &&
        n.path.GetPosition().y == maze.GetGoal().y) {
      return n.path;
    }
    auto next_paths = n.path.GetNextPaths(maze);
    for (int i = 0; i < next_paths.size(); i++) {
      if (n.path.GetDirections().size() == 0) {
        open.push({next_paths.at(i), n.cumulative_cost + 1});
        continue;
      }
      int rotate_cost =
          std::abs((DirectionToInt(n.path.GetDirections().back()) -
                    DirectionToInt(next_paths.at(i).GetDirections().back())));
      int acc_cost = rotate_cost == 0 ? 0 : 3;
      open.push(
          {next_paths.at(i), n.cumulative_cost + 1 + rotate_cost + acc_cost});
    }
    // PrintMaze(maze, n.path);
    // std::cout << "\033[34A" << std::flush;
    // std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }
}
}  // namespace maze_solver
