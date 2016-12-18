/**
*	@file MedicalExecutive.h
*	@author Robert Hümmer
*	@date 17.12.2016
*	@brief	A header file for MedicalExecutive class
* 			Reads in the initial list of cities
* 			maintains the infected cities and quarantined cities list
* 			maintains the required ordering by population
*/
#ifndef MEDICAL_EXECUTIVE_H
#define MEDICAL_EXECUTIVE_H

#include "LinkedList.h"
#include "City.h"
#include <string>
#include <vector>
using namespace std;


class MedicalExecutive
{
private:
	LinkedList<City> m_infectedCityList;
	LinkedList<City> m_quarantinedCityList;
	
	void split(const string& s, char delimiter, vector<string>& elems);
	
	
public:
	MedicalExecutive() = delete;
	MedicalExecutive(char * p_fileName);
	void run();
	
	
	/**
	 * @Pre		create a node and specify a cmp_data which the LL is sorted by.
	 * @Post	the specified node of type T is inserted in the LL so that the LL is in Order.
	 * @return	None
	 */
	template <typename T>
	static void insertInOrderIntoLL(LinkedList<T>& ll, T node, int cmp_data);
};


template <typename T>
void MedicalExecutive::insertInOrderIntoLL(LinkedList<T>& ll, T node, int cmp_data)
{
	int inputPos;
	for(inputPos=1; inputPos <= ll.getLength(); ++inputPos)
	{
		if( cmp_data >= ll.getEntry(inputPos) ) 	// insert position found!
		{
			ll.insert(inputPos, node);
			break;
		}
	}
	// a position of >= could not be found so addBack
	if( inputPos == ll.getLength()+1 )	
		ll.insert(inputPos, node);
}

#endif
