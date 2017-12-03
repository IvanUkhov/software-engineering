#include <string>

#include "gtest/gtest.h"
#include "structure/map/hash.h"

const std::size_t kCount = 100;

typedef structure::map::Hash<std::string, int> Map;

TEST(MapTest, HashInsert) {
  Map map;
  map.Insert("key0", 42);
  for (std::size_t i = 0; i < kCount; i++) {
    map.Insert("key" + std::to_string(i), i);
  }
  map.Insert("key1", 42);
  ASSERT_EQ(map.Size(), kCount);
}
