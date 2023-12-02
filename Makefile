SHELL = /usr/bin/env bash
.PHONY: clean

CC = g++
CCFLAGS = -Wall -Werror -Wextra -std=c++20 -g -O
CCAFTER = -lncurses

main: main.o
	$(CC) $(CCFLAGS) -o main main.o $(CCAFTER)

clean:
	rm -f main *.o *.plain
