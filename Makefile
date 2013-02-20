# Makefile for CS130a PA2
PACKAGE	=	tripe

all:
	g++ -std=c++0x src/*.cpp -o prog1

run_test: test/test.cpp
	g++ -std=c++0x src/*.cpp test/*.cpp -g -o test/test
