#include "fixture.h"
#include "gtest/gtest.h"
#include "problem/string_permutations.h"

namespace {

template <typename T>
void Assess(T process, const std::string& input, const std::string& output) {
  std::stringstream buffer;
  process(input, buffer);
  std::string actual = fixture::Sort(buffer.str());
  std::string expected = fixture::Clean(output);
  ASSERT_EQ(actual, expected);
}

}

TEST(ProblemTest, StringPermutationsUniqueChars) {
  Assess(problem::StringPermutationsUniqueChars, "a", "a");
  Assess(problem::StringPermutationsUniqueChars, "abc", R"(
abc
acb
bac
bca
cab
cba
)");
}

TEST(ProblemTest, StringPermutationsNonuniqueChars) {
  Assess(problem::StringPermutationsNonuniqueChars, "a", "a");
  Assess(problem::StringPermutationsNonuniqueChars, "aabc", R"(
aabc
aacb
abac
abca
acab
acba
baac
baca
bcaa
caab
caba
cbaa
)");
}
