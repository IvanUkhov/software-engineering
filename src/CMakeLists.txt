set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  )

add_library(
  interview
  problem/check_palindrome.cc
  problem/count_pairs.cc
  problem/find_permutations.cc
  problem/list_permutations.cc
  problem/solve_cubes.cc
  problem/urlify_space.cc
  )
