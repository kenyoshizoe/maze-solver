#include "maze-solver/solver/breadth_first.h"

#include <algorithm>
#include <iostream>
#include <queue>

#include <thread>

namespace maze_solver {
Path BreadthFirst::Solve(Maze maze) {
  std::queue<Path> open;
  Path start(maze.GetStart());
  open.push(start);

  int count = 0;
  int max_count = 1;

  while (true) {
    if (open.empty()) {
      return Path(maze.GetStart());
    }

    Path n = open.front();
    open.pop();
    PrintMaze(maze, n);

    if (n.GetPosition().x == maze.GetGoal().x &&
        n.GetPosition().y == maze.GetGoal().y) {
      return n;
    }
    auto next_paths = n.GetNextPaths(maze);
    for (int i = 0; i < next_paths.size(); i++) {
      open.push(next_paths.at(i));
    }
  }
}
}  // namespace maze_solver
