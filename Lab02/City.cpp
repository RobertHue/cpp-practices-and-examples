/**
*	@file City.cpp
*	@author Robert Hümmer
*	@date 17.12.2016
*	@brief A implementation file for City class
*/
#include "City.h"
#include <string>
using namespace std;

City::City(string cityName, int population, int infectionLevel) :
	m_cityName(cityName),
	m_population(population),
	m_infectionLevel(infectionLevel)
{}

const string& City::getCityName() const
{
	return m_cityName;
}
void City::setCityName(const string& newCityName)
{
	m_cityName = newCityName;
} 

int City::getPopulation() const
{
	return m_population;
}
void City::setPopulation(int population)
{
	m_population = population;
}

int City::getInfectionLevel() const
{
	return m_infectionLevel;
}
void City::increaseInfectionLevelByOne()
{
	++m_infectionLevel;
}
