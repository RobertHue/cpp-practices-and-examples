//Filename: Sort.h
//Description: Class declaration for Sort class
//Assignment: EECS 268 Lab7
//Author: Henry C. Nguyen
//Email: h724n828@ku.edu
//Date; 4-9-2014
//

#ifndef SORT_H
#define SORT_H

#include "BogoSort.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"

template<typename T>
class Sort {
public:
	//@pre parameters match type and exist
	//@post sorts arr[] in ascending order
	//@return none
	void bogoSort(T arr[], int size);

	//@pre parameters match type and exist
	//@post sorts arr[] in ascending order
	//@return none
	void bubbleSort(T arr[], int size);

	//@pre parameters match type and exist
	//@post sorts arr[] in ascending order
	//@return none
	void insertionSort(T arr[], int size);
	
	//@pre parameters match type and exist
	//@post sorts arr[] in ascending order
	//@return none
	void mergeSort(T arr[], int size);

	//@pre parameters match type and exist
	//@post sorts arr[] in ascending order
	//@return none
	void quickSort(T arr[], int size);

	//@pre parameters match type and exist
	//@post sorts arr[] in ascending order
	//@return none
	void quickSortMedian(T arr[], int size);
private:
	BogoSort<T> BogoSorter;
	BubbleSort<T> BubbleSorter;
	InsertionSort<T> InsertionSorter;
	MergeSort<T> MergeSorter;
	QuickSort<T> QuickSorter;
};

#include "Sort.hpp"

#endif
