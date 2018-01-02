#include <initializer_list>
#include <utility>

#include "gtest/gtest.h"
#include "structure/tree/search.h"

struct Value : public std::pair<int, const char*> {
  Value(int first, const char* second = nullptr) : pair(first, second) {}

  bool operator<(const Value& other) const {
    return first < other.first;
  }
};

using Tree = structure::tree::BinarySearch<Value>;

namespace {

Tree Create() {
  Tree tree;
  tree.Insert({8, "a"})
      .Insert({3, "b"})
      .Insert({1, "c"})
      .Insert({6, "d"})
      .Insert({4, "e"})
      .Insert({7, "f"})
      .Insert({10, "g"})
      .Insert({14, "h"})
      .Insert({13, "i"});
  return tree;
}

} // namespace

TEST(TreeTest, BinarySearchInsert) {
  ASSERT_EQ(Create().Root()->Right()->Right()->Left()->Value().first, 13);
}

TEST(TreeTest, BinarySearchSearch) {
  ASSERT_EQ(Create().Search({10})->Value().second, "g");
  ASSERT_EQ(Create().Search({42}), nullptr);
}
