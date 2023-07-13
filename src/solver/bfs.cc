#include "maze-solver/solver/bfs.h"

#include <queue>

namespace maze_solver {
Path BFS::Solve(Maze maze) {
  std::queue<Path> open;
  Path start(maze.GetStart());
  open.push(start);
  while (true) {
    if (open.empty()) {
      return Path(maze.GetStart());
    }
    Path n = open.front();
    open.pop();
    // PrintMaze(maze, n);
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
