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
  algorithm/search/binary.cc
  algorithm/sort/bubble.cc
  algorithm/sort/count.cc
  algorithm/sort/heap.cc
  algorithm/sort/insertion.cc
  algorithm/sort/merge.cc
  algorithm/sort/quick.cc
  algorithm/sort/radix.cc
  algorithm/sort/selection.cc
  algorithm/sort/tree.cc
  problem/count_pairs.cc
  problem/find_permutations.cc
  problem/list_permutations.cc
  problem/solve_cubes.cc
  structure/list/forward.cc
  structure/map/hash.cc
  structure/queue/impartial.cc
  structure/stack/array.cc
  structure/tree/heap.cc
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
