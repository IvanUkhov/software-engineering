#ifndef PROBLEM_ROBOT_MAZE_H_
#define PROBLEM_ROBOT_MAZE_H_

#include <cstddef>
#include <utility>
#include <vector>

namespace problem {

using Maze = std::vector<bool>;
using Path = std::vector<std::pair<std::size_t, std::size_t>>;

Path RobotMaze(const Maze& maze, std::size_t rows, std::size_t columns);

} // namespace problem

#endif // PROBLEM_ROBOT_MAZE_H_
