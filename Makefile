##
## Makefile for GPIO LED Button example
## Author: Stf
## Date:   12.11.2015

all: main

main: main.o
	gcc -o main main.o -l wiringPi

main.o: main.c main.h
	gcc -ansi -pedantic -Wall -c main.c main.h

clean:
	rm -f main main.o

