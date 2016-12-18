 /**
*	@file City.h
*	@author Robert Hümmer
*	@date 17.12.2016
*	@brief 	A header file for City class
* 			Holds the information for one City
*/
#ifndef CITY_H
#define CITY_H

#include <string>
using namespace std;

class City
{
private:
	string 	m_cityName;
	int		m_population;
	int 	m_infectionLevel;
public:
	City() = delete;	// no compiler generated default constructor
	City(string cityName, int population, int infectionLevel);
	
	/**
	 * @brief	Two cities are equal when they have the same name
	 * @return	true  if the cities have the same name
	 * 			false if not
	 */
	bool operator==(const City& rhs) const
	{
		return this->m_cityName.compare( rhs.getCityName() ) == 0 ? true : false;
	}
	
	const string& getCityName() const;
	
	int getPopulation() const;
	void setPopulation(int population);  
	
	int getInfectionLevel() const;
	void increaseInfectionLevelByOne();
};


#endif
