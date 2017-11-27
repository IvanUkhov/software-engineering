#include <ctime>

#include "fixture.h"

namespace fixture {

void Randomize() {
  static bool done = false;
  if (!done) {
    std::srand(std::time(0));
    done = true;
  }
}

} // namespace fixture
