//Filename: BogoSort.h
//Description: Class method and variable declarations for BogoSort
//Assignment: EECS 268 Lab 7
//Author: Henry C. Nguyen
//Email: h724n828@ku.edu
//Date: 4-9-2014
//

#ifndef BOGOSORT_H
#define BOGOSORT_H

template<typename T>
class BogoSort {
public:
	//@pre parameters match correct type and exist
	//@post for every element in parameter array, select random index and swap
	//@return none
	void sort(T arr[], int size);

	//@pre parameters match correct type and exist
	//@post none
	//@return ascending sort state of array 
	bool isSorted(T arr[], int size);
private:

};

#include "BogoSort.hpp"

#endif
