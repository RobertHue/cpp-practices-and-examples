//Filename: MergeSort.hpp
//Description: Definitions for MergeSort class
//Author: Henry C. Nguyen
//Assignment: EECS 268 Lab 6
//Email: h724n828@ku.edu
//Date: 4-4-14

#include "MergeSort.h"

template<typename T>
MergeSort<T>::~MergeSort() {
	//pop all pointers off stack
	while(!pointers.empty()) {
		delete[] pointers.top();
		pointers.pop();
	}
}

//recursively calls mergeArray and copies result to original array
template<typename T>
void MergeSort<T>::sort(T arr[], int size) {
	T* targetArray = new T[size];
	pointers.push(targetArray);
	targetArray = mergeSort(arr, size);
	for(int i = 0; i<size; ++i) {
		arr[i] = targetArray[i];
	}
}

template<typename T>
T* MergeSort<T>::merge(T* left, T* right, int sizeLeft, int sizeRight) {
	int size = sizeLeft + sizeRight;
	if(size > 1) {
		T* mergedArray = new T[size];
		pointers.push(mergedArray);
		int i = 0;
		int j = 0;
		int k = 0;
		//compares while either left or right have not been completely exhausted
		while(i < sizeLeft && j < sizeRight) {
			//Compare current left and right elements
			if(left[i] <= right[j]) {
				mergedArray[k] = left[i];
				i++; //move to next leftElement
			}
			else
			{
				mergedArray[k] = right[j];
				j++; //move to next rightElement
			}
			//increment to next mergedArray element
			k++;
		}
		//dump rest of left in merged array if not completely exhausted
		while(i < sizeLeft) {
			mergedArray[k] = left[i];
			i++;
			k++;
		}
		//or dump rest of right in merged array if not completely exhausted
		while(j < sizeRight) {
			mergedArray[k] = right[j];
			j++;
			k++;
		}
		return mergedArray;
	}
	else {
		if(sizeLeft > sizeRight) {
			return left;
		}
		else {
			return right;
		}
	}
}

template<typename T>
T* MergeSort<T>::mergeSort(T* arr, int size) {
	if(size > 1) {
		//Split left and right branches
		int midpoint = 0.5*size;
		T* left = new T[midpoint];
		T* right = new T[size-midpoint];
		pointers.push(left);
		pointers.push(right);
		for(int i = 0; i<midpoint;++i) {
			left[i] = arr[i];
		}
		for(int i = midpoint;i<size;++i) {
			right[i-midpoint] = arr[i];
		}
		
		//merge sort left and then right
		left = mergeSort(left,midpoint);
		right = mergeSort(right,size-midpoint);
		//merge two branches together
		return merge(left,right, midpoint, size-midpoint);
	}
	else {
		return arr;
	}
}
