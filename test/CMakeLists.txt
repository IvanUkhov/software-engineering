set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

set(GOOGLETEST_SOURCE_DIR
  ${PROJECT_SOURCE_DIR}/vendor/googletest/googletest CACHE STRING "Google Test"
  )

set(GOOGLETEST_SOURCES
  ${GOOGLETEST_SOURCE_DIR}/src/gtest-all.cc
  ${GOOGLETEST_SOURCE_DIR}/src/gtest_main.cc
  )

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${PROJECT_SOURCE_DIR}/src
  ${GOOGLETEST_SOURCE_DIR}
  ${GOOGLETEST_SOURCE_DIR}/include
  )

foreach(source ${GOOGLETEST_SOURCES})
  set_source_files_properties(${source} PROPERTIES GENERATED 1)
endforeach()

add_library(googletest ${GOOGLETEST_SOURCES})

add_executable(
  tester
  main.cc
  fixture.cc
  algorithm/search/a_star.cc
  algorithm/search/bellman_ford.cc
  algorithm/search/binary.cc
  algorithm/search/dijkstra.cc
  algorithm/sort/bubble.cc
  algorithm/sort/bucket.cc
  algorithm/sort/count.cc
  algorithm/sort/heap.cc
  algorithm/sort/insertion.cc
  algorithm/sort/merge.cc
  algorithm/sort/quick.cc
  algorithm/sort/radix.cc
  algorithm/sort/selection.cc
  algorithm/sort/tree.cc
  problem/balanced_tree.cc
  problem/binary_search.cc
  problem/bit_insertion.cc
  problem/build_order.cc
  problem/char_replacement.cc
  problem/common_ancestor.cc
  problem/common_subsequence.cc
  problem/factorial_zeros.cc
  problem/fibonacci.cc
  problem/fixed_difference.cc
  problem/four_cubes.cc
  problem/free_fields.cc
  problem/list_duplicates.cc
  problem/list_tail.cc
  problem/magic_index.cc
  problem/matrix_rotation.cc
  problem/median_tracker.cc
  problem/meter_jump.cc
  problem/minimal_tree.cc
  problem/multi_stack.cc
  problem/nested_permutations.cc
  problem/one_away.cc
  problem/palindrome_permutations.cc
  problem/parenthesis_combinations.cc
  problem/power_set.cc
  problem/rectangle_intersection.cc
  problem/recursive_multiply.cc
  problem/robot_maze.cc
  problem/stack_sort.cc
  problem/string_combinations.cc
  problem/string_compression.cc
  problem/string_permutations.cc
  problem/string_rotation.cc
  problem/two_permutations.cc
  problem/unique_chars.cc
  problem/zero_matrix.cc
  structure/graph/adjacency_list.cc
  structure/list/forward.cc
  structure/map/hash.cc
  structure/queue/impartial.cc
  structure/stack/array.cc
  structure/stack/list.cc
  structure/tree/bayer.cc
  structure/tree/binary.cc
  structure/tree/fenwick.cc
  structure/tree/heap.cc
  structure/tree/red_black.cc
  structure/tree/search.cc
  structure/tree/trie.cc
  )

add_dependencies(tester googletest)

target_link_libraries(
  tester
  googletest
  interview
  pthread
  )
