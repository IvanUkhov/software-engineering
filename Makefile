build := build

all: test

test:
	mkdir -p "${build}" && cd "${build}" && cmake .. && make && ./test

clean:
	rm -rf "${build}"

.PHONY: clean test
