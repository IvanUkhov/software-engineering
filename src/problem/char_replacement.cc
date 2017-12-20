#include "problem/char_replacement.h"

void problem::CharReplacement(std::string& string, std::size_t length) {
  int count = 0;
  for (int i = 0; i < length; ++i) {
    if (string[i] == ' ') ++count;
  }
  int j = int(length) - count + 3 * count - 1;
  for (int i = int(length) - 1; i >= 0; --i) {
    if (string[i] != ' ') {
      string[j--] = string[i];
    } else {
      string[j--] = '0';
      string[j--] = '2';
      string[j--] = '%';
    }
  }
}
