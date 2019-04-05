all: main.o
	g++ -g -std=c++11 main.o -o lab7

main.o: main.cpp BogoSort.h BogoSort.hpp BubbleSort.h BubbleSort.hpp InsertionSort.h InsertionSort.hpp MergeSort.h MergeSort.hpp QuickSort.h QuickSort.hpp Sort.h Sort.hpp
	g++ -g -std=c++11 -c main.cpp

clean:
	rm *.o

wipe:
	rm lab7
