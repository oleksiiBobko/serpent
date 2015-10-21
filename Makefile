CC = gcc -Wall -g

SRC = snake.c common.c game.c 

OBJS = $(SRC:.c=.o)
LIBS = -lncurses

all: snake 

.c.o:
	$(CC) -c $*.c -o $*.o

snake: $(OBJS)
	$(CC) $(LIBS) $(OBJS)  -o $@

.PHONY: clean
clean: 
	rm -f *~ *.o snake 

PREFIX = /usr/local

install: snake
	    mkdir -p $(DESTDIR)$(PREFIX)/bin
		    cp $< $(DESTDIR)$(PREFIX)/bin/snake

uninstall:
	    rm -f $(DESTDIR)$(PREFIX)/bin/snake


