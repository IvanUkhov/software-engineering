build := build

all: test

build:
	mkdir -p "${build}" && cd "${build}" && cmake .. && make

test: build
	cd "${build}" && ./tester

test-all: build
	cd "${build}" && ./tester --gtest_also_run_disabled_tests

clean:
	rm -rf "${build}"

.PHONY: all build clean test test-all
