#include "gtest/gtest.h"
#include "problem/robot_maze.h"

TEST(ProblemTest, RobotMaze) {
  const std::size_t rows = 10;
  const std::size_t columns = 10;
  problem::Maze maze = {};
  auto actual = problem::RobotMaze(maze, rows, columns);
  problem::Path expected = {};
  ASSERT_EQ(actual, expected);
}
