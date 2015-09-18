CC = gcc -Wall -g

SRCS = snake.c common.c game.c 

OBJS = $(SRCS:.c=.o)
LIBS = -lncurses

#INSTALL=/usr/bin/install -c
#INSTALL_FOLDER=/usr/games

all: snake 

.c.o:
	$(CC) -c $*.c -o $*.o

snake: $(OBJS)
	$(CC) $(LIBS) $(OBJS)  -o $@

clean: 
	rm -f *~ *.o snake 

#install:
#	$(INSTALL) nibbles $(INSTALL_FOLDER) -g games
#	chmod g+s $(INSTALL_FOLDER)/nibbles
#	touch /var/lib/games/nibbles.score
#	chown root.games /var/lib/games/nibbles.score
#	chmod 664 /var/lib/games/nibbles.score
#	cp -a nibbles.levels $(INSTALL_FOLDER)
#	chmod 644 $(INSTALL_FOLDER)/nibbles.levels/*
#	chown root.games $(INSTALL_FOLDER)/nibbles.levels/*
##
#install-rpm:
#	$(INSTALL) nibbles $(RPM_BUILD_ROOT)/$(INSTALL_FOLDER)
####	touch $(RPM_BUILD_ROOT)/var/lib/games/nibbles.score
###	chmod 664 $(RPM_BUILD_ROOT)/var/lib/games/nibbles.score
#	cp -a nibbles.levels $(RPM_BUILD_ROOT)/$(INSTALL_FOLDER)
#	chmod 644 $(RPM_BUILD_ROOT)/$(INSTALL_FOLDER)/nibbles.levels/*
#
#uninstall:
#	rm $(INSTALL_FOLDER)/nibbles
#	rm /var/lib/games/nibbles.score
#	rm $(INSTALL_FOLDER)/nibbles.levels -rf
