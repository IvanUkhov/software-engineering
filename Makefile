test:
	mkdir -p build && cd build && cmake .. && make && ./test

.PHONY: test
