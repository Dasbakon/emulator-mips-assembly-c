#makefile

all: main

main: main.c
	gcc main.c -o main -Wall -ansi -pedantic -std=c11