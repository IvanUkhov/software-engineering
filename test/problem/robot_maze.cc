#include "gtest/gtest.h"
#include "problem/robot_maze.h"

TEST(ProblemTest, RobotMaze) {
  const std::size_t rows = 10;
  const std::size_t columns = 10;
  problem::Maze maze = {
    1, 1, 1, 1, 1, 0, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 0, 1, 1, 1, 1,
    1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
    1, 1, 0, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 0, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 0, 0, 0, 1, 0, 0, 0, 0,
    1, 1, 0, 1, 1, 1, 0, 1, 1, 1,
    1, 1, 0, 1, 0, 1, 0, 1, 1, 1,
    1, 1, 1, 1, 0, 1, 1, 1, 1, 1,
  };
  auto actual = problem::RobotMaze(maze, rows, columns);
  problem::Path expected = {
    {0, 0}, {0, 1}, {1, 1}, {2, 1}, {3, 1},
    {4, 1}, {5, 1}, {5, 2}, {5, 3}, {5, 4},
    {5, 5}, {6, 5}, {7, 5}, {8, 5}, {9, 5},
    {9, 6}, {9, 7}, {9, 8}, {9, 9},
  };
  ASSERT_EQ(actual, expected);
}
