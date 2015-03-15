//Filename: main.cpp
//Description: Entry point for lab 7 program
//Assignment: EECS 268 Lab 7
//Author: Henry C. Nguyen
//Email: h724n828@ku.edu
//Date: 4-9-2014
//

#include <iostream>
#include <string>
#include <sys/time.h>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include "Sort.h"

#define CALL_SORT_FUNC(instance, funcPtrToSort) ( (instance).*(funcPtrToSort) )

typedef void (Sort<double>::*SortFunction)(double arr[], int size);

unsigned long getTime() {
	timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec * 1000000ul + tv.tv_usec;
}

void printSortTime(SortFunction sorts[], Sort<double>& s, int index,
std::string name, unsigned long timeLimit) {
	unsigned long start = getTime();
	int size = 1;
	int totalPassed = 0;

	//Calculates amount of time it takes to do max passings in time limit
	while((getTime()-start) < timeLimit) {
		double randomArray[size];
		for(int i = 0; i<size; ++i) {
			randomArray[i] = drand48();
		}
		CALL_SORT_FUNC(s, sorts[index])(randomArray,size);
		totalPassed = totalPassed + size;
		size = size + 1;		
	}

	unsigned long totalTime = getTime() - start;
	std::cout << name << "\t\t: " << totalPassed  <<
	" in a total of " << totalTime << " micro secs " << std::endl;

}
int main(int argc, char* argv[]) {
	srand(time(NULL));
	Sort<double> Sorter;
	int arraySize = 7;
	double array[arraySize];

	for(int i = 0; i<arraySize; ++i) {
		array[i] = drand48();
	}
	
	//Serts up a array of function pointers
	SortFunction sorts[] = { &Sort<double>::bogoSort,
				&Sort<double>::bubbleSort,
				&Sort<double>::insertionSort,
				&Sort<double>::mergeSort,
				&Sort<double>::quickSort,
				&Sort<double>::quickSortMedian
				};
	
	unsigned long bogoStart = getTime();
	CALL_SORT_FUNC(Sorter, sorts[0])(array, arraySize);
	unsigned long bogoTotaltime = getTime() - bogoStart;
	std::cout << "Time required for bogo sort to sort " << arraySize << " numbers: " << bogoTotaltime << " micro secs" <<
	std::endl << "In that amount of time, other sorts can sort the following amounts: " << std::endl <<
	"------------------------------------------------------" << std::endl;

	printSortTime(sorts, Sorter, 1, "Bubble Sort", bogoTotaltime);
	printSortTime(sorts, Sorter, 2, "Insertion Sort", bogoTotaltime);
	printSortTime(sorts, Sorter, 3, "Merge Sort", bogoTotaltime);
	printSortTime(sorts, Sorter, 4, "Quick Sort", bogoTotaltime);
	printSortTime(sorts, Sorter, 5, "Quick Sort with Median", bogoTotaltime);
	return 0;
}


