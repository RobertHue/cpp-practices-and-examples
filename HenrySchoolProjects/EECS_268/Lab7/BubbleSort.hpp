//Filename: BubbleSort.hpp
//Assignment: EECS 268 Lab 7
//Description: Definitions for Bubble Sort class
//Author: Henry C. Nguyen
//Email: h724n828@ku.edu
//Date: 4-9-14 

#include "BubbleSort.h"

template<typename T>
BubbleSort<T>::BubbleSort() {

}

template<typename T>
void BubbleSort<T>::sort(T arr[], int size) {
	for(int i = 1; i < size; ++i) {
		for(int j = 0; j < size-1; ++j) {
			if(arr[j] > arr[j+1]){
				//swap position current bubble meets
				//sorting conditions
				T temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}
