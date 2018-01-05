#include <algorithm>
#include <ctime>
#include <sstream>
#include <vector>

#include "fixture.h"

namespace fixture {

std::string Clean(const std::string& string) {
  std::stringstream istream(string);
  std::stringstream ostream;
  std::string line;
  while (std::getline(istream, line)) {
    if (!line.empty()) ostream << line << '\n';
  }
  return ostream.str();
}

std::string Sort(const std::string& string) {
  std::stringstream istream(string);
  std::vector<std::string> lines;
  std::string line;
  while (std::getline(istream, line)) lines.push_back(line);
  std::sort(lines.begin(), lines.end());
  std::stringstream ostream;
  for (auto& line : lines) ostream << line << '\n';
  return ostream.str();
}

void Randomize() {
  static bool done = false;
  if (!done) {
    std::srand(std::time(0));
    done = true;
  }
}

template <>
std::vector<double> Generate<double>(std::size_t size) {
  std::vector<double> data;
  data.reserve(size);
  for (auto value : Generate<int>(size)) {
    data.push_back((double)value / RAND_MAX);
  }
  return data;
}

} // namespace fixture
