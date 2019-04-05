//Filename: InsertionSort.hpp
//Description: Class method definitions for InsertionSort class
//Assignment: EECS 268 Lab 7
//Author: Henry C. Nguyen
//Email: h724n828@ku.edu
//Date: 4-9-2014
//

#include "InsertionSort.h"

//Sorts given array using insertion technique
template<typename T>
void InsertionSort<T>::sort(T arr[], int size) {
	int insert;
	int j;
	for(int i = 1; i<(size); ++i) {
		insert = arr[i];
		j = i;
		while(j > 0 && arr[j - 1] > insert) {
			arr[j] = arr[j-1];
			j = j - 1;
		}
		arr[j] = insert;
	}
}
