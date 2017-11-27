cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(interview)

enable_language(CXX)

set (CMAKE_CXX_STANDARD 11)

include_directories(
  ${PROJECT_SOURCE_DIR}/src
  )

add_library(
  interview
  src/structure/tree/search/binary.cc
  )

set(GOOGLETEST_SOURCE_DIR
  vendor/googletest/googletest CACHE STRING "Google Test"
  )

set(GOOGLETEST_SOURCES
  ${PROJECT_SOURCE_DIR}/${GOOGLETEST_SOURCE_DIR}/src/gtest-all.cc
  ${PROJECT_SOURCE_DIR}/${GOOGLETEST_SOURCE_DIR}/src/gtest_main.cc
  )

include_directories(
  ${PROJECT_SOURCE_DIR}/${GOOGLETEST_SOURCE_DIR}
  ${PROJECT_SOURCE_DIR}/${GOOGLETEST_SOURCE_DIR}/include
  )

foreach(source ${GOOGLETEST_SOURCES})
  set_source_files_properties(${source} PROPERTIES GENERATED 1)
endforeach()

add_library(googletest ${GOOGLETEST_SOURCES})

add_executable(
  tester
  test/main.cc
  test/structure/tree/heap/binary.cc
  test/structure/tree/search/binary.cc
  )

add_dependencies(tester googletest)

target_link_libraries(
  tester
  googletest
  interview
  pthread
  )
