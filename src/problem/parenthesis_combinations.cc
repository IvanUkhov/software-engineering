#include <string>

#include "problem/parenthesis_combinations.h"

void ParenthesisCombinations(std::size_t count, std::size_t left,
                             std::size_t right, std::string& string,
                             std::ostream& output) {
  if (left == count && right == count) {
    output << string << '\n';
    return;
  }
  if (left < count) {
    string.push_back('(');
    ParenthesisCombinations(count, left + 1, right, string, output);
    string.pop_back();
  }
  if (right < left) {
    string.push_back(')');
    ParenthesisCombinations(count, left, right + 1, string, output);
    string.pop_back();
  }
}

void problem::ParenthesisCombinations(std::size_t count, std::ostream& output) {
  std::string string;
  ::ParenthesisCombinations(count, 0, 0, string, output);
}
