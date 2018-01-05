#include "fixture.h"
#include "gtest/gtest.h"
#include "problem/string_permutations.h"

namespace {

template <typename T>
void Assess(T process, const std::string& input, std::string expected) {
  std::stringstream output;
  process(input, output);
  ASSERT_EQ(fixture::Sort(output.str()), fixture::Clean(expected));
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
