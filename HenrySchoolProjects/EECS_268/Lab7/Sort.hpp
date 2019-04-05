//Filename: Sort.hpp
//Description: Class method definitions for Sort class
//Assignment: EECS 268 Lab 7
//Author: Henry C. Nguyen
//Email: h724n828@ku.edu
//Date: 4-9-14
//

template<typename T>
void Sort<T>::bogoSort(T arr[], int size) {
	while(!BogoSorter.isSorted(arr, size)) {
		BogoSorter.sort(arr, size);
	}
}

template<typename T>
void Sort<T>::bubbleSort(T arr[], int size) {
	BubbleSorter.sort(arr, size);
}

template<typename T>
void Sort<T>::insertionSort(T arr[], int size) {
	InsertionSorter.sort(arr, size);
}

template<typename T>
void Sort<T>::mergeSort(T arr[], int size) {
	MergeSorter.sort(arr, size);
}

template<typename T>
void Sort<T>::quickSort(T arr[], int size) {
	QuickSorter.sort(arr, size);
}

template<typename T>
void Sort<T>::quickSortMedian(T arr[], int size) {
	QuickSorter.sortWithMedian(arr, size);
}
