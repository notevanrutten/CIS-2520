CC = gcc
CCFLAGS = -Wall -std=c99 -pedantic

make:
	$(CC) $(CCFLAGS) -o q1 q1.c
	$(CC) $(CCFLAGS) -o q2 q2.c