#ifndef PROBLEM_RECTANGLE_INTERSECTION_H_
#define PROBLEM_RECTANGLE_INTERSECTION_H_

#include <utility>

namespace problem {

template <typename T>
struct CenterRectangle {
  T x;
  T y;
  T width;
  T height;
};

template <typename T>
struct CornerRectangle {
  T x;
  T y;
  T width;
  T height;
};

// Determine if two rectangles intersect. Give another algorithm where
// rectangles are defined by their width, height, and (x, y) coordinates of
// their centers.
template <typename T>
bool RectangleIntersection(const CenterRectangle<T>& one,
                           const CenterRectangle<T>& other) {
  return false;
}

// Determine if two rectangles intersect. Give an algorithm to solve this
// problem when rectangles are defined by their width, height, and (x, y)
// coordinates of their top-left corners.
template <typename T>
bool RectangleIntersection(const CornerRectangle<T>& one,
                           const CornerRectangle<T>& other) {
  return false;
}

} // namespace problem

#endif // PROBLEM_RECTANGLE_INTERSECTION_H_
