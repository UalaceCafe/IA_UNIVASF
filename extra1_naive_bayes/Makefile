all: run

SOURCES = src/main.cpp src/stats.cpp

.PHONY: run compile

compile:
	g++ -Wall -pedantic -O2 -std=c++20 -Werror $(SOURCES) -o bin/main

run: compile
	./bin/main
