#include "gtest/gtest.h"
#include "problem/rectangle_intersection.h"

TEST(ProblemTest, RectangleIntersectionCenter) {
  using Rectangle = problem::CenterRectangle<int>;

  Rectangle rectangle1 = {2, 2, 4, 4};
  Rectangle rectangle2 = {5, 5, 2, 4};
  Rectangle rectangle3 = {7, 3, 4, 2};
  Rectangle rectangle4 = {7, 4, 2, 2};

  ASSERT_FALSE(problem::RectangleIntersection(rectangle1, rectangle2));
  ASSERT_FALSE(problem::RectangleIntersection(rectangle1, rectangle3));
  ASSERT_FALSE(problem::RectangleIntersection(rectangle1, rectangle4));

  ASSERT_FALSE(problem::RectangleIntersection(rectangle2, rectangle1));
  ASSERT_TRUE(problem::RectangleIntersection(rectangle2, rectangle3));
  ASSERT_FALSE(problem::RectangleIntersection(rectangle2, rectangle4));

  ASSERT_FALSE(problem::RectangleIntersection(rectangle3, rectangle1));
  ASSERT_TRUE(problem::RectangleIntersection(rectangle3, rectangle2));
  ASSERT_TRUE(problem::RectangleIntersection(rectangle3, rectangle4));

  ASSERT_FALSE(problem::RectangleIntersection(rectangle4, rectangle1));
  ASSERT_FALSE(problem::RectangleIntersection(rectangle4, rectangle2));
  ASSERT_TRUE(problem::RectangleIntersection(rectangle4, rectangle3));
}

TEST(ProblemTest, RectangleIntersectionCorner) {
  using Rectangle = problem::CornerRectangle<int>;

  Rectangle rectangle1 = {0, 4, 4, 4};
  Rectangle rectangle2 = {4, 7, 2, 4};
  Rectangle rectangle3 = {5, 4, 4, 2};
  Rectangle rectangle4 = {6, 5, 2, 2};

  ASSERT_FALSE(problem::RectangleIntersection(rectangle1, rectangle2));
  ASSERT_FALSE(problem::RectangleIntersection(rectangle1, rectangle3));
  ASSERT_FALSE(problem::RectangleIntersection(rectangle1, rectangle4));

  ASSERT_FALSE(problem::RectangleIntersection(rectangle2, rectangle1));
  ASSERT_TRUE(problem::RectangleIntersection(rectangle2, rectangle3));
  ASSERT_FALSE(problem::RectangleIntersection(rectangle2, rectangle4));

  ASSERT_FALSE(problem::RectangleIntersection(rectangle3, rectangle1));
  ASSERT_TRUE(problem::RectangleIntersection(rectangle3, rectangle2));
  ASSERT_TRUE(problem::RectangleIntersection(rectangle3, rectangle4));

  ASSERT_FALSE(problem::RectangleIntersection(rectangle4, rectangle1));
  ASSERT_FALSE(problem::RectangleIntersection(rectangle4, rectangle2));
  ASSERT_TRUE(problem::RectangleIntersection(rectangle4, rectangle3));
}
