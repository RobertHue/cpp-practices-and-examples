//============================================================================
// Name        : cpp_algorithms.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "quicksort.h"



int main() {
	cout << "::::Test of various Algorithms::::" << endl;


	// Init:
	int arr[] = { 1, 12, 5, 26, 7, 14, 3, 7, 2 };
	int arr_size = sizeof(arr)/sizeof(float);
	quicksort<int>(arr, arr_size);

	// output the array:
	for(int i=0; i < arr_size; ++i)
	{
		cout << "arr[" << i << "] = " << arr[i] << endl;
	}
	////////////////////////////////////////////
	float fArr[] = {3.0f/4, 2.333f, 255.57, 111, 1.0f/5, 1.0f/6, 3.0f/4, 23.354839};
	int fArr_size = sizeof(fArr)/sizeof(float);
	quicksort<float>(fArr, fArr_size);
	cout << endl << endl;
	for(int i=0; i < fArr_size; ++i)
	{
		cout << "fArr[" << i << "] = " << fArr[i] << endl;
	}
	////////////////////////////////////////////
	char alphabet[] = "qwertzuiopasdfghjklyxcvbnm";	// char-array
	int cArr_size = sizeof(alphabet)/sizeof(char);
	it_quicksort<char>(alphabet, cArr_size);
	cout << endl << endl;
	for(int i=0; i < cArr_size; ++i)
	{
		cout << "alphabet[" << i << "] = " << alphabet[i] << " (" << static_cast<int>(alphabet[i]) << ")" << endl;
	}
	return 0;
}
