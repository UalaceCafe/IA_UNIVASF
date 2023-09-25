all: run

SOURCES = src/main.c src/utils.c src/population.c src/genetic.c

.PHONY: run compile

compile:
	gcc -Wall -pedantic -O2 -std=c17 -Werror $(SOURCES) -o bin/main

run: compile
	./bin/main
