CC=gcc
CFLAGS=-Iinclude
DEPS = HTTP_Server.h
exec = bin/server
sources = $(wildcard src/*.c)
objects = $(patsubst src/%.c,bin/%.o,$(sources))
flags = -g -Wall -lm -ldl -fPIC -rdynamic -I./include

$(exec): $(objects)
	mkdir -p bin
	$(CC) $(objects) $(flags) -o $(exec)

bin/%.o: src/%.c
	mkdir -p bin
	$(CC) -c $(flags) $< -o $@

clean:
	-rm -f *.out
	-rm -f *.o
	-rm -f *.a
	-rm -f src/*.a
	-rm -f bin/*.o
	-rm -f bin/server
	-rm -rf bin