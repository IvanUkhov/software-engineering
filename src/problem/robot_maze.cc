#include <cassert>
#include <unordered_set>

#include "problem/robot_maze.h"

namespace problem {

namespace internal {

bool RobotMaze(const Maze& maze, std::size_t rows, std::size_t columns,
               std::size_t i, std::size_t j, Path& path,
               std::unordered_set<std::size_t>& cache) {
  cache.insert(i * columns + j);
  path.push_front({i, j});
  if (i == 0 && j == 0) return true;
  if (i > 0) {
    auto k = (i - 1) * columns + j;
    if (maze[k] &&
        cache.count(k) == 0 &&
        RobotMaze(maze, rows, columns, i - 1, j, path, cache)) return true;
  }
  if (j > 0) {
    auto k = i * columns + (j - 1);
    if (maze[k] &&
        cache.count(k) == 0 &&
        RobotMaze(maze, rows, columns, i, j - 1, path, cache)) return true;
  }
  path.pop_front();
  return false;
}

} // namespace internal

Path RobotMaze(const Maze& maze, std::size_t rows, std::size_t columns) {
  assert(rows > 0 && columns > 0);
  Path path;
  std::unordered_set<std::size_t> cache;
  internal::RobotMaze(maze, rows, columns, rows - 1, columns - 1, path, cache);
  return path;
}

} // namespace problem
