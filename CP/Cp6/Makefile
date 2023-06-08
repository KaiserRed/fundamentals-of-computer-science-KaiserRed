CC=gcc
CFLAGS=-Wall -Werror -Wextra -Wfatal-errors -Wpedantic -pedantic-errors -std=c18
LDFLAGS=
LDLIBS=
EXECUTABLE=bin/pdump bin/pselect
DIRS=bin


all: $(DIRS) $(EXECUTABLE)

$(DIRS):
	mkdir -p $(DIRS)

bin/pdump: bin/computer.o bin/dump_computer.o
	$(CC) $(LDFLAGS) bin/computer.o bin/dump_computer.o $(LDLIBS) -o $@

bin/pselect: bin/computer.o bin/main.o 
	$(CC) $(LDFLAGS)  bin/computer.o bin/main.o  $(LDLIBS) -o $@

bin/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf bin/*.o $(EXECUTABLE)

debug: CFLAGS+=-Og -g

.PHONY: all debug clean