CFLAGS = -g -Wall
CC = gcc

solver: main.o parameters.o
	$(CC) $(CFLAGS) -o main main.o parameters.o

main.o: header.h main.cpp
	$(CC) $(CFLAGS) -c main.cpp

parameters.o: header.h parameters.cpp
	$(CC) $(CFLAGS) -c parameters.cpp