#Copyright (c) 2013 Julian Sparber <julian@sparber.net>
PROGNAME=coin_amount
CC=gcc
CFLAGS= -std=c90 -Os -Wall
OBJ= main.o

all: 
	$(CC) $(CFLAGS) -o $(PROGNAME) $(PROGNAME).c

clean: 
	rm -rf $(PROGNAME) $(PROGNAME) $(OBJ) *~
