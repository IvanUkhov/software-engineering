#include <string>

#include "gtest/gtest.h"
#include "structure/map/hash.h"

const std::size_t kCount = 100;

typedef structure::map::Hash<std::string, int> Map;

TEST(MapTest, HashOverwrite) {
  Map map;
  map.Set("key0", 42);
  for (std::size_t i = 0; i < kCount; i++) {
    map.Set("key" + std::to_string(i), i);
  }
  map.Set("key1", 42);
  ASSERT_EQ(map.Size(), kCount);
  ASSERT_EQ(*map.Get("key0"), 0);
  ASSERT_EQ(*map.Get("key1"), 42);
}

TEST(MapTest, HashNotFound) {
  Map map;
  map.Set("foo", 42);
  ASSERT_EQ(map.Get("bar"), nullptr);
}

TEST(MapTest, HashResize) {
  Map map;
  ASSERT_EQ(map.Length(), 1 << 7);
  for (std::size_t i = 0; i < 2 * kCount; i++) {
    map.Set("key" + std::to_string(i), i);
  }
  ASSERT_EQ(map.Length(), 1 << 8);
}
