/*
 * quicksort.h
 *
 *  Created on: 02.12.2016
 *      Author: Robert
 */

#ifndef QUICKSORT_H_
#define QUICKSORT_H_

/// @brief	the function template being used (class has the same effect!)
template<typename T>
void my_swap(T& left, T& right)
{
	T tmp = right;
	right = left;
	left  = tmp;
}

/// @brief		the partition algorithm of the quicksort
/// @param1		the array being partitioned
/// @param2		the lowest index
/// @param3		the highest index
/// @return		0 mustnt be reached, >0 returns the final index
template<typename T>
int partition (T * array, int idxLeft, int idxRight)
{
	int i = idxLeft-1, j = idxRight+1;
	T pivot = array[(idxRight-idxLeft)/2 + idxLeft];	// Vergleichselement waehlen
	while(1)
	{
		// solange von i-Zeiger nach rechts suchen, bis ein Element erreicht wurde, das kleiner ist als Pivot
		do ++i;	while(array[i] < pivot);

		// solange von j-Zeiger nach links suchen, bis ein Element erreicht wurde, das groesser ist als Pivot
		do --j;	while(array[j] > pivot);

		// falls Element-Zeiger sich treffen gebe diesen zurueck
		if( i >= j )	break;

		// ansonsten, tausche Elemente & weiterhangeln (postfix-increment):
		my_swap( array[i], array[j] );
	}
	// throw 0;	// should not be reached!
	return j;
}

/// @brief	sorts the given array with quicksort (recursive with the help of the stack)
///	@param1	the array which will get sorted
/// @param2 the lowest index of the array where quicksort will start
/// @param3 the highest index of the array ....
/// @note	partition scheme described by C.A.R. Hoare
/// 		becareful with the size of the stack use the iterative quicksort instead
template<typename T>
void quicksort( T * array, int idxLeft, int idxRight )
{
	if( idxLeft < idxRight )
	{
		int idxPart = partition<T>(array, idxLeft, idxRight);
		quicksort<T>( array, idxLeft, idxPart);			// sort the left partition
		quicksort<T>( array, idxPart+1, idxRight);		// sort the right partition
	}
}

/// @brief	sorts the given array with quicksort (recursive with the help of the stack)
///	@param1	the array which will get sorted
/// @param3 the size of the array
/// @note	partition scheme described by C.A.R. Hoare
/// 		becareful with the size of the stack use the iterative quicksort instead
template<typename T>
void quicksort( T * a, int size )
{
	try{
		if( a == nullptr )	throw nullptr;
	} catch (exception& e) {
		cerr << "Exception: " << e.what() << endl;
	}

	quicksort<T>( a, 0, size-1 );
}

#include <stack>
#include <deque>
#include <vector>
#include <typeinfo.h>
template<typename T>
void it_quicksort( T * a, int size )
{
	try{
		if( a == nullptr )	throw nullptr;
	} catch (exception& e) {
		cerr << "Exception: " << e.what() << endl;
	}

	std::stack<int> stack;
	stack.push(0); stack.push(size-1);		// + Custom Stack: nur linker und rechter Teil werden gespeichert
	int i, j, ug, og, k, d;
	T x, y, z;	// Kandidaten für Schlüssel
	while(!stack.empty())	// Solange Stack nicht leer ist
	{
		og = stack.top(); stack.pop();
		ug = stack.top(); stack.pop();
		while(ug<og)
		{
			i=ug;
			j=og;
			k=(i+j)/2;	// Kandidaten für Schlüssel
			d=(j-i)/4;

			y=a[i+d];
			z=a[j-d];
			if(y>a[k])
			{
				if(z>y)	k=i+d;
				else if(z>a[k])	k=j-d;
			} else {
				if(z<y)	k=i+d;
				else if(z<a[k])	k=j-d;
			}
			x=a[k];		// + Clever Quicksort: Mittlerer von drei Schlüsseln
			while(i<=j)	// Partition hier
			{
				while(a[i]<x) i++;
				while(a[j]>x) j--;

				if(i<=j) {
					y=a[i]; a[i]=a[j]; a[j]=y;
					i++;
					j--;
				}
			}
			if((j-ug) < (og-i)) {	// großere Zerlegung auf Stack
				if(i<og) {			// Stackeintrag rechts
					stack.push(i);
					stack.push(og);
				}
				og=j;
			} else {
				if(ug<j) {
					stack.push(ug);
					stack.push(j);
				}
				ug=i;
			}
		}
	}
}

#endif /* QUICKSORT_H_ */
