//Filename: QuickSort.h
//Description: Class declaration for QuickSort class
//Assignment: EECS 268 Lab 7
//Author: Henry C. Nguyen
//Email: h724n828@ku.edu
//Date: 4-9-2014
//

#ifndef QUICKSORT_H
#define QUICKSORT_H

template<typename T>
class QuickSort {
public:
	//@pre parameters match type and exist
	//@post sorts arr[] in ascending order using quicksort technique
	//@return none
	void sort(T arr[], int size);
	
	//@pre parameters match type and exist
	//@post sorts arr[] using quicksort technique and median
	//@return none
	void sortWithMedian(T arr[], int size);	
private:
	//@pre paramters match type andn exist
	//@post recusively calls quicksort to partition array
	//@return none
	void quickSort(T arr[], int first, int last, bool median);

	//@pre parameters match type and exist
	//@post sets last element of array to median value
	//@return none
	void setMedianPivot(T arr[], int first, int last);

	//@pre parameters must match type and exist
	//@post partitions values less than pivot to left of pivot and greater
	//values to the right of pivot
	//@returns index of partitioned array
	int partition(T arr[], int first, int last, bool median);

};

#include "QuickSort.hpp"

#endif
