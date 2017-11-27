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
  structure/tree/heap/binary.cc
  structure/tree/search/binary.cc
  )

add_dependencies(tester googletest)

target_link_libraries(tester googletest interview pthread)
