#include "problem/hanoi_towers.h"

void problem::HanoiTowers(Stack& a, Stack& b, Stack& c) {
  auto slide = [](Stack& one, Stack& other) {
    if (one.IsEmpty() && other.IsEmpty()) return;
    else if (one.IsEmpty()) one.Push(other.Pop());
    else if (other.IsEmpty()) other.Push(one.Pop());
    else if (one.Peek() > other.Peek()) one.Push(other.Pop());
    else other.Push(one.Pop());
  };
  while (!a.IsEmpty() || !b.IsEmpty()) {
    slide(a, b);
    slide(a, c);
    slide(b, c);
  }
}
