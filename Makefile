.PHONY: all
all: build quality

# NOTE: This is a bit hacky, but it's good enough for a project of this scale
.PHONY: setup
setup:
	mkdir build-gcc
	CC=gcc-14 CXX=g++-12 cmake -G Ninja -B build-gcc -S .

	mkdir build-clang
	CC=clang-18 CXX=clang++-18 cmake -G Ninja -B build-clang -S .

	ln -s build-gcc build
	ln -s build-clang/compile_commands.json

.PHONY: clean
clean:
	rm -rf build-gcc build-clang build compile_commands.json

.PHONY: build
build:
	cmake --build build-gcc/
	cmake --build build-clang/

.PHONY: quality
quality:
	poetry run pre-commit run --all-files
