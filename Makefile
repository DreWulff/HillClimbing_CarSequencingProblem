CFLAGS = -g -Wall
CC = g++

solver: main.o parameters.o
	$(CC) $(CFLAGS) -o main main.o parameters.o

main.o: main.cpp
	$(CC) -c main.cpp

parameters.o: parameters.cpp
	$(CC) -c parameters.cpp

.PHONY : clean
clean :
	-rm *.o $(objects) main