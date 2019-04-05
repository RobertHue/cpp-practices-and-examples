//Filename: QuickSort.hpp
//Description: Class method definitions for QuickSort
//Assignment: EECS 268 Lab 7
//Author: Henry C. Nguyen
//Email: h724n828@ku.edu
//Date: 4-9-2014
//

//public methods
template<typename T>
void QuickSort<T>::sort(T arr[], int size) {
	quickSort(arr, 0, (size-1), false);
}

template<typename T>
void QuickSort<T>::sortWithMedian(T arr[], int size) {
	quickSort(arr, 0, (size-1), true);
}

//private methods
template<typename T>
void QuickSort<T>::quickSort(T arr[], int first, int last , bool median) {
	if(first < last) {
		int partitionIndex  = partition(arr, first, last, median);

		quickSort(arr, first, partitionIndex-1, median);
		quickSort(arr, partitionIndex+1, last, median);
	}	
}

template<typename T>
void QuickSort<T>::setMedianPivot(T arr[], int first, int last) {
	int median = last/2;
	T swap = arr[median];
	arr[median] = arr[last];
	arr[last] = swap;
}

template<typename T>
int QuickSort<T>::partition(T arr[], int first, int last, bool median) {
	if(median == true) {
		setMedianPivot(arr, first, last);
	}

	T pivot = arr[last];
	int partitionIndex = first;

	for(int i = first; i<last; ++i) {
		if(arr[i] <= pivot) {
			T swap = arr[i];
			arr[i] = arr[partitionIndex];
			arr[partitionIndex] = swap;
			++partitionIndex;
		}
	}
	T swap = arr[partitionIndex];
	arr[partitionIndex] =  arr[last];
	arr[last] = swap;

	return partitionIndex;
}
