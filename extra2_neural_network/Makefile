all: run

SOURCES = src/main.c src/ann.c

.PHONY: run compile

compile:
	gcc -Wall -pedantic -O2 -std=c2x -Werror $(SOURCES) -o bin/main

run: compile
	./bin/main $(GATE)
