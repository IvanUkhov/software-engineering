set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  )

add_library(
  interview
  problem/char_replacement.cc
  problem/factorial_zeros.cc
  problem/fixed_difference.cc
  problem/four_cubes.cc
  problem/minimal_tree.cc
  problem/nested_permutations.cc
  problem/palindrome_permutations.cc
  problem/string_combinations.cc
  problem/string_permutations.cc
  )
