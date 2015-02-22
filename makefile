all: main

main: main.o
	g++ main.o -o main

main.o: main.cpp puzzle.h
	g++ -c main.cpp

clean:
	rm *.o main
