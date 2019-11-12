#makefile

all: emulator

emulator: emulator.c
	gcc emulator.c -o emulator -Wall -ansi -pedantic -std=c11