build := build

all: test

test:
	mkdir -p "${build}" && cd "${build}" && cmake .. && make && ./tester

clean:
	rm -rf "${build}"

.PHONY: all clean test
