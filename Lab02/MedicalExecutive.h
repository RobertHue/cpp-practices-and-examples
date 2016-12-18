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
	
	/**
	 * @Pre		create a City
	 * @Post	the specified City of type T is inserted in the LL so that the LL is in Order.
	 * 			In order means first sort by population, then by infectionLeven, and then by cityName
	 * @return	None
	 */
	void insertCityNodeIntoLL(LinkedList<City>& ll, City& cityNode);
	
	/**
	 * @Pre		None
	 * @Post	applies actions on the city based on the requirements of the lab
	 * @return	None
	 */
	void applyActionOnCity(City& city);
	
public:
	MedicalExecutive() = delete;
	MedicalExecutive(char * p_fileName);
	void run();
	
	
};



#endif
