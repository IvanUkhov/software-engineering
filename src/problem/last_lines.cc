#include <string>
#include <vector>

#include "problem/last_lines.h"

void problem::LastLines(std::size_t count, std::istream& input,
                        std::ostream& output) {
  ++count;
  std::size_t read = 0;
  std::vector<std::string> lines(count);
  while (std::getline(input, lines[read++ % count]));
  if (read < count) {
    count = read;
    read = 0;
  }
  for (std::size_t i = 1; i < count; ++i) {
    output << lines[read++ % count] << '\n';
  }
}
