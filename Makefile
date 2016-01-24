CC = gcc -Wall -g

SRC = serpent.c common.c game.c 

OBJS = $(SRC:.c=.o)
LIBS = -lncurses -lm

all: serpent 

.c.o:
	$(CC) -c $*.c -o $*.o

serpent: $(OBJS)
	$(CC)  $(OBJS) $(LIBS) -o $@

.PHONY: test
test:
	@echo $(value PREFIX)

.PHONY: clean
clean: 
	rm -f *~ *.o serpent 

PREFIX = /usr/local

install: serpent
	    mkdir -p $(DESTDIR)$(PREFIX)/bin
		    cp $< $(DESTDIR)$(PREFIX)/bin/serpent

uninstall:
	    rm -f $(DESTDIR)$(PREFIX)/bin/serpent


