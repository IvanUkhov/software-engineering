#include "structure/stack/assess.h"
#include "structure/stack/list.h"

TEST(StackTest, List) {
  structure::stack::Assess<structure::stack::List<int>>();
}
