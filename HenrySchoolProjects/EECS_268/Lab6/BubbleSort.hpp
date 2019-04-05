//Filename: BubbleSort.hpp
//Assignment: EECS 268 Lab 6
//Description: Definitions for Bubble Sort class
//Author: Henry C. Nguyen
//Email: h724n828@ku.edu
//Date: 4-4-14 

#include "BubbleSort.h"

template<typename T>
BubbleSort<T>::BubbleSort() {

}

template<typename T>
void BubbleSort<T>::sort(T arr[], int size) {
	for(int i = 0; i < size; ++i) {
		if(arr[i] < arr[i+1]) {
			//swap position current bubble meets
			//sorting conditions
			T temp = arr[i];
			arr[i] = arr[i+1];
			arr[i+1] = temp;
		}
	}
}
