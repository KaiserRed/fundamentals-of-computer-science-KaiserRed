CC=gcc
RM=rm -fr
CFLAGS=-Wall -Werror -Wextra -Wfatal-errors -Wpedantic -pedantic-errors -std=c18
LDFLAGS=
LDLIBS=
SOURCES=main.c stack.c sort.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=main

debug: CFLAGS+=-Og -g
debug: all

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) $(LDLIBS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) *.o $(EXECUTABLE)