//Filename: main.cpp
//Assignment: EECS 268 Lab 6
//Description: Entry point for lab6 program and dislays required timings for bubble and merge sorting methods
//Author: Henry C. Nguyen
//Email: h724n828@ku.edu
//Date 4-4-13

#include <iostream>
#include <sys/time.h>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include "BubbleSort.h"
#include "MergeSort.h"

unsigned long getTime() {
	timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec * 1000000ul + tv.tv_usec;
}

int main(int argc, char* argv[]) {

	//initialize random generator
	srand(time(NULL));

	BubbleSort<double> BubbleSorter;
	std::cout << "# of elements\tbubble sort time\tmerge sort time" << std::endl;
	for(int N = 10; N < 100001; N*=10) {
		//Create random arrays
		MergeSort<double>* MergeSorter = new MergeSort<double>();
		double randBubbleSort[N];
		double randMergeSort[N];
		for(int i = 0; i<N; ++i) {
			randBubbleSort[i] = drand48();
			randMergeSort[i] = randBubbleSort[i];
		}
	
		//time bubble sort
		unsigned long bubStart = getTime();
		BubbleSorter.sort(randBubbleSort,N);
		unsigned long bubTotal = getTime() - bubStart;

		//time merge sort
		unsigned long merStart = getTime();
		MergeSorter->sort(randMergeSort,N);
		unsigned long merTotal = getTime() - merStart;

		//deletes object off heap to clear private members
		delete MergeSorter;
		std::cout << N << "\t\t" << bubTotal << "\t\t\t" << merTotal << std::endl;
	}

	return 0;
}
