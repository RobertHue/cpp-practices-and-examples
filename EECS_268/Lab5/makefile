all: main.o
	g++ -g -std=c++11 main.o -o lab5

main.o: main.cpp Node.h Node.hpp BinarySearchTree.h BinarySearchTree.hpp
	g++ -g -std=c++11 -c main.cpp

clean:
	rm *.o

wipe:
	rm lab5
