#Makefile for Assignment 3

all: nn


nn: main.o mat.o rand.o
	g++  -o nn main.o mat.o rand.o


main.o: main.cpp
	g++  -g -c main.cpp

mat.o: mat.h

rand.o: rand.h


clean:
	rm nn
	rm -f main.o mat.o
