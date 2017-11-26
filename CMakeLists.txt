cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(interview)

enable_language(CXX)

include_directories(
  ${PROJECT_SOURCE_DIR}/src
  )

add_library(
  interview
  src/structure/tree/search/binary.cc
  )

set(GOOGLETEST_SOURCE_DIR vendor/googletest/googletest CACHE STRING "Google Test")

include_directories(
  ${PROJECT_SOURCE_DIR}/${GOOGLETEST_SOURCE_DIR}
  ${PROJECT_SOURCE_DIR}/${GOOGLETEST_SOURCE_DIR}/include
  )

set(GOOGLETEST_SOURCES
  ${PROJECT_SOURCE_DIR}/${GOOGLETEST_SOURCE_DIR}/src/gtest-all.cc
  ${PROJECT_SOURCE_DIR}/${GOOGLETEST_SOURCE_DIR}/src/gtest_main.cc
  )

foreach(_source ${GOOGLETEST_SOURCES})
  set_source_files_properties(${_source} PROPERTIES GENERATED 1)
endforeach()

add_library(googletest ${GOOGLETEST_SOURCES})

add_executable(
  tester
  test/main.cc
  test/structure/tree/search/binary.cc
  )

add_dependencies(tester googletest)

target_link_libraries(
  tester
  googletest
  interview
  pthread
  )

include(CTest)
enable_testing()

add_test(test ${PROJECT_BINARY_DIR}/test)
