all: main.o
	g++ -g -std=c++11 main.o -o lab6

main.o: main.cpp BubbleSort.h BubbleSort.hpp
	g++ -g -std=c++11 -c main.cpp

clean:
	rm *.o

wipe:
	rm lab6 
