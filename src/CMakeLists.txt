set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  )

add_library(
  interview
  problem/char_replacement.cc
  problem/fixed_difference.cc
  problem/four_cubes.cc
  problem/nested_permutation.cc
  problem/palindrome_permutation.cc
  problem/string_permutation.cc
  )
