//Filename: BogoSort.hpp
//Description: Class method definitions for BogoSort
//Assignment: EECS 268 Lab 7
//Author: Henry C. Nguyen
//Email: h724n828@ku.edu
//Date: 4-9-2014
//

#include <cstdlib>
#include <ctime>
#include "BogoSort.h"

#include <iostream>

template<typename T>
void BogoSort<T>::sort(T arr[], int size) {
	int randomIndex;
	for(int i = 0; i<size; ++i) {
		//Initialize random number generator
		srand(time(NULL));
		//Keeps random value within bounds of array index
		randomIndex = rand()%(size+1);
		//Swaps values
		T swap = arr[i];
		arr[i] = arr[randomIndex];
		arr[randomIndex] = swap;
	}
}

template<typename T>
bool BogoSort<T>::isSorted(T arr[], int size) {
	//Tests arr[] for ascending order and returns true if
	//successful otherwise return false
	for(int i = 0; i<(size-1); ++i) {
		if(arr[i] > arr[i+1]) {
			return false;
		}
	}
	return true;
}	

