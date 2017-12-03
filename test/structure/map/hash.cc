#include <string>

#include "gtest/gtest.h"
#include "structure/map/hash.h"

const std::size_t kCount = 100;

typedef structure::map::Hash<std::string, int> Map;

TEST(MapTest, HashSetGet) {
  Map map;
  map.Set("key0", 42);
  for (std::size_t i = 0; i < kCount; i++) {
    map.Set("key" + std::to_string(i), i);
  }
  map.Set("key1", 42);
  ASSERT_EQ(map.Size(), kCount);
  ASSERT_EQ(*map.Get("key0"), 0);
  ASSERT_EQ(*map.Get("key1"), 42);
  ASSERT_EQ(map.Get("key"), nullptr);
}
