CC=g++
CFLAGS= -c -Wall -std=c++11

test: Skiplist.o test.o
	$(CC) Skiplist.o test.o -o test

Skiplist.o: Skiplist.cpp
	$(CC) $(CFLAGS) Skiplist.cpp

test.o: test.cpp
	$(CC) $(CFLAGS) test.cpp

clean:
	rm *o test