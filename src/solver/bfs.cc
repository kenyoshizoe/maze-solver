#include "maze-solver/solver/bfs.h"

#include <iostream>
#include <queue>
#include <thread>

#include "maze-solver/visualizer/print.h"

namespace maze_solver {
Path BFS::Solve(Maze maze) {
  // for performance measurement
  if (print_solving_perfomance_) {
    std::cout << "[BFS] Start Solving..." << std::endl;
  }
  int order_count = 0;
  auto start_time = std::chrono::system_clock::now();
  int max_container_size = 0;

  std::queue<Path> open;
  Path start(maze.GetStart());
  open.push(start);
  while (true) {
    if (open.empty()) {
      if (print_solving_perfomance_) {
        std::cout << "Solve Failed." << std::endl;
      }
      return Path(maze.GetStart());
    }
    Path n = open.front();
    open.pop();
    if (n.GetPosition().x == maze.GetGoal().x &&
        n.GetPosition().y == maze.GetGoal().y) {
      if (print_solving_perfomance_) {
        PrintSolvingPerfomance(n, order_count, start_time, max_container_size);
      }
      return n;
    }
    auto next_paths = n.GetNextPaths(maze);
    for (int i = 0; i < next_paths.size(); i++) {
      open.push(next_paths.at(i));
    }

    if (print_solving_process_) {
      PrintMaze(maze, n);
      std::cout << "\033[34A" << std::flush;
      std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    order_count++;
    max_container_size = std::max(max_container_size, (int)open.size());
  }
}
}  // namespace maze_solver
