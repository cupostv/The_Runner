CC=gcc

all: map tests build
.PHONY: map tests build

map:
	$(CC) -c src/map.c -o ../build/map.o
tests:
	$(MAKE) -C tests all
build:
	$(MAKE) -C build all
