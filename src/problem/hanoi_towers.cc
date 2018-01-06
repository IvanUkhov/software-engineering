#include "problem/hanoi_towers.h"

namespace problem {

static void Slide(Stack& one, Stack& other) {
  if (one.IsEmpty() && other.IsEmpty()) return;
  else if (one.IsEmpty()) one.Push(other.Pop());
  else if (other.IsEmpty()) other.Push(one.Pop());
  else if (one.Peek() > other.Peek()) one.Push(other.Pop());
  else other.Push(one.Pop());
}

void HanoiTowers(Stack& a, Stack& b, Stack& c) {
  while (!a.IsEmpty() || !b.IsEmpty()) {
    Slide(a, b);
    Slide(a, c);
    Slide(b, c);
  }
}

} // namespace problem
