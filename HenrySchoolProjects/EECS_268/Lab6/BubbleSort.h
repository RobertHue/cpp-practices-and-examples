//Filename: BubbleSort.h
//Assignment: EECS 268 Lab 6
//Author: Henry C. Nguyen
//KUID: 2465007
//Description: Header file containing declarations for BubbleSort class
//Email: h724n828@ku.edu
//Date: 2-28-14

#ifndef BUBBLESORT_H
#define BUBBLESORT_H

template<typename T>
class BubbleSort {
public:
	//@pre none
	//@post none
	//@return none
	BubbleSort();

	//@pre array parameter must match template type
	//and type is assumed to use numbers to overload < operator
	//properly
	//size parameter must match int type.
	//@post sorts parameter array in bubble sort method
	//@return none
	void sort(T arr[], int size);
};

#include "BubbleSort.hpp"

#endif
