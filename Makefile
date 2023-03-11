
# Variables to control Makefile operation

CC = g++
CFLAGS = -Wall -g

linked-list-cycle: linked-list-cycle.o
	$(CC) $(CFLAGS) -o linked-list-cycle linked-list-cycle.o

linked-list-cycle.o: linked-list-cycle.cpp
	$(CC) $(CFLAGS) -c linked-list-cycle.cpp

clean:
	rm -rf linked-list-cycle linked-list-cycle.o
