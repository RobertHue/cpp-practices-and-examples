//Filename: InsertionSort.h
//Description: Class declaration for InsertionSort
//Assignment: EECS 268 Lab 7
//Author: Henry C. Nguyen
//Email: h724n828@ku.edu
//Date: 4-9-2014
//

#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

template<typename T>
class InsertionSort {
public:
	//@pre parameters match type and exist
	//@post sorts array using insertion sort technique
	//@return none
	void sort(T arr[], int size);		

private:
};

#include "InsertionSort.hpp"

#endif
