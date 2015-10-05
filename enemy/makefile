CC=gcc

all: enemy tests build
.PHONY: enemy tests build

enemy:
	$(CC) -c src/enemy.c -o ../build/enemy.o
tests:
	$(MAKE) -C tests all
build:
	$(MAKE) -C build all
