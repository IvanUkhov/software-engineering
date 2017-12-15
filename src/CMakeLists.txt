set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  )

add_library(
  interview
  problem/find_permutations.cc
  problem/fixed_difference.cc
  problem/list_permutations.cc
  problem/palindrome_permutation.cc
  problem/solve_cubes.cc
  problem/urlify_space.cc
  )
