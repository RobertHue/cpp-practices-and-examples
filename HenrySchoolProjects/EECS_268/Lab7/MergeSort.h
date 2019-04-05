//Filename: MergeSort.h
//Assignment: EECS 268 Lab 7
//Description: Header declarations for MergeSort class 
//Author: Henry C. Nguyen
//Email: h724n828@ku.edu
//Date: 4-9-14
#ifndef MERGESORT_H
#define MERGESORT_H

#include <stack>

template<typename T>
class MergeSort {
public:
	//@pre none
	//@post deletes and pops all pointer arrays off pointers stack
	//@return none
	~MergeSort();

	//@pre array input must match type and exist
	//@post sorts array using mergesort recursively
	//@return none
	void sort(T arr[], int size);
private:
	//@pre left and right must be valid type and existence
	//@post merges left and right branches together in ordered fashion
	//@return pointer to merged array
	T* merge(T* left, T* right, int sizeLeft, int sizeRight);

	//@pre array must exist and match type
	//@post splits arr into left and right branches then merges in sorted fashion
	//@return pointer to merged array
	T* mergeSort(T* arr, int size);

	//keeps track of all dynamically allocated memory for deconstructor
	std::stack<T*> pointers;
};

#include "MergeSort.hpp"

#endif
