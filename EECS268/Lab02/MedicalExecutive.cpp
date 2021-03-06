 /**
*	@file MedicalExecutive.cpp
*	@author Robert Hümmer
*	@date 17.12.2016
*	@brief A implementation file for MedicalExecutive class
*/
#include "MedicalExecutive.h"
#include "LinkedList.h"
#include "City.h"
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <limits>
using namespace std;

MedicalExecutive::MedicalExecutive(char * p_fileName) :
	m_infectedCityList(),
	m_quarantinedCityList()
{
	string line;
	
	// open the file to be read
	ifstream fileStream(p_fileName);
	
	// check if stream has associated file
	if( fileStream.is_open() == false )
	{	
		throw runtime_error("unable to open file! \
							Please input file data into program!");
	}
	
	// read new line until eof
	while( getline(fileStream, line) ) 
	{
		// push the space-seperated line into vector "results"
		vector<string> results;
		split( line, ',', results );
		
		// coordinate the reading of the data into the LL
		City newCity = City(results[0], stoi(results[1]), stoi(results[2]));
		
		// add it back to the list (helps to keep the list sorted by population)
		insertCityNodeIntoLL(m_infectedCityList, newCity);
	}
	// close the file stream
	fileStream.close();
}
void MedicalExecutive::run()
{
	int choice; 
	do
	{
		cout << "################################################" << endl;
		cout << "Make a selection:" << endl;
		cout << "1) Increase infection level of all cities" << endl;
		cout << "2) Increase infection level of specific city" << endl;
		cout << "3) Print status of a specific city" << endl;
		cout << "4) Create quarantine log" << endl;
		cout << "5) Print all cities above an infection level" << endl;
		cout << "6) Exit" << endl;
		cout << "Choice: ";
		cin >> choice;
		// recovering from bad user input:
		while( cin.fail() )
		{
			cin.clear();	// unset failbit
			cin.ignore(numeric_limits<streamsize>::max(), '\n');	// skip bad input (ignore until \n)
			cout << "Sorry, your input did not seem to be an int. Please try again! " << endl;
			cout << "Choice: ";
			cin >> choice;
		}
		 
		switch(choice)
		{  
			case 1:	// Increase infection level of all cities
			{
				for(int i=1; i <= m_infectedCityList.getLength(); ++i)
				{
					City cityLL = m_infectedCityList.getEntry(i);
					cout << "i: " << i << endl;
					cityLL.increaseInfectionLevelByOne();
					applyActionOnCity( cityLL );
				}
				cout << "The infection level for all cities has been increased." << endl;				
				break;
			}
			case 2:	// Increase infection level of specific city
			{
				string cityName;
				cout << "Which city do you want to infect?: ";
				cin >> cityName;
				cin.get();	// remove \n from cin
				
				City city(cityName, 0, 0);	// dummy object for finding the city
				int position = m_infectedCityList.positionOf(city);
				City cityLL = m_infectedCityList.getEntry(position);
				cityLL.increaseInfectionLevelByOne();
				applyActionOnCity( cityLL );
				break;
			}
			case 3:	// Print status of a specific city
			{
				string cityName;
				cout << "Which city's status do you want to print out?: ";
				cin >> cityName;
				cin.get();	// remove \n from cin
				
				City city(cityName, 0, 0);	// dummy object for finding the city
				int position = m_infectedCityList.positionOf(city);
				City cityLL = m_infectedCityList.getEntry(position);
				
				cout << "City : " << cityLL.getCityName() << endl;
				cout << "Population : " << cityLL.getPopulation() << endl;
				cout << "InfectionLevel : " << cityLL.getInfectionLevel() << endl;
				break;
			}
			case 4:	// Create quarantine log
			{
				string fileName;
				cout << "Please enter the fileName where you want to store the quarantine log?: ";
				cin >> fileName;
				cin.get();	// remove \n from cin
				
				// open the file to be read
				ofstream fileStream(fileName);
				
				// check if stream has associated file
				if( fileStream.is_open() == false )
				{	
					throw runtime_error("unable to open file! \
										Please input file data into program!");
				}
				
				// write the quarantinedCities into the quarantine log:
				for(int i=1; i<=m_quarantinedCityList.getLength(); ++i)
				{
					City cityLL = m_quarantinedCityList.getEntry(i);
					fileStream << cityLL.getCityName() << 
						", " << cityLL.getPopulation() << 
						", " << cityLL.getInfectionLevel() << endl;
				} 
				
				
				// close the file stream
				fileStream.close();
				break;
			}
			case 5:	// Print all cities above an infection level
			{
				int infectionLevel;
				cout << "Please enter the infection level?: ";
				cin >> infectionLevel;
				cin.get();	// remove \n from cin
				
				for(int i=1; i<=m_infectedCityList.getLength(); ++i)
				{
					City cityLL = m_infectedCityList.getEntry(i);
					if( cityLL.getInfectionLevel() >= infectionLevel )
					{
						cout << "City: " << cityLL.getCityName() << 
							"\tPopulation: " << cityLL.getPopulation() << 
							"\tInfectionLevel: " << cityLL.getInfectionLevel() << endl;
					}
				}
				break;
			}
			case 6:	// Exit
			{
				break;
			}
			default:
			{
				cout << "Wrong inpt! Please try again" << endl;
			}
		}
	} while (choice != 6);
	cout << "\nThanks for checking infection outbreak!\nBye." << endl;
}

void MedicalExecutive::applyActionOnCity(City& city)
{
	int infectionLevel = city.getInfectionLevel();
	switch( infectionLevel )
	{
		case 0:	/* do nothing */
		{
			break;
		}
		case 1:
		{
			// remove this city from the list
			m_infectedCityList.removeAt( m_infectedCityList.positionOf(city) );
			
			// decrease the population by 10% (rounded down = truncated)
			city.setPopulation( city.getPopulation() * 0.90 );
			
			// add it back to the list (helps to keep the list sorted by population)
			insertCityNodeIntoLL(m_infectedCityList, city);
			break;
		}
		case 2:
		{
			// remove this city from the list
			m_infectedCityList.removeAt( m_infectedCityList.positionOf(city) );
			
			// decrease the population by 20% (rounded down = truncated)
			city.setPopulation( city.getPopulation() * 0.80 );
			
			// add it back to the list (helps to keep the list sorted by population)
			insertCityNodeIntoLL(m_infectedCityList, city);
			break;
		}
		case 3:
		{
			// both cities should be removed and added back to the list as before
			m_infectedCityList.removeAt( m_infectedCityList.positionOf(city) );
			
			// take 25% (rounded down = truncated) of the population and form a new city
			// note: when forming a new city the name of the city will be the old name with a "New " in front
			string newName("New ");
			city.setCityName( newName.append( city.getCityName() ) );
			city.setPopulation( city.getPopulation() * 0.75 );
			
			insertCityNodeIntoLL(m_infectedCityList, city);
			break;
		}
		case 4:
		{
			// all hope is lost for the city
			// => the city is removed from the infected list and moved to the quarantined list (with its remaining inhabitants
			m_infectedCityList.removeAt( m_infectedCityList.positionOf(city) );
			insertCityNodeIntoLL( m_quarantinedCityList, city);
			
			// => a message "City X has been placed in quarantine" is printed to the screen
			cout << "City " << city.getCityName() << " has been placed in quarantine" << endl;
			// => this city can no longer be interacted with other than to be saved in the quarantine log
			// note: once a city is moved to quarantine, it does not change infection level nor population
			break;
		}
		default:
		{
			// undefined infectionLevel... do nothing...
		}
	}
}

void MedicalExecutive::insertCityNodeIntoLL(LinkedList<City>& ll, City& cityNode)
{
	int inputPos; 
	for(inputPos=1; inputPos <= ll.getLength(); ++inputPos)
	{
		City c = ll.getEntry(inputPos);
		if( cityNode.getPopulation() > c.getPopulation() ) 	// greater population
		{
			ll.insert(inputPos, cityNode);
			break;
		}
		// if population tied => then sort by infectionLevel
		else if( cityNode.getPopulation() == c.getPopulation() ) 	// same population (tied)
		{
			if( cityNode.getInfectionLevel() > c.getInfectionLevel() )	// greater infectionLevel
			{
				ll.insert(inputPos, cityNode);
				break;
			}
			// if infectionLevel tied => then sort by cityName
			else if( cityNode.getCityName().compare( c.getCityName() ) >= 0 )
			{
				ll.insert(inputPos, cityNode);
				break;
			}
		}
	}
	// a position of >= could not be found so addBack
	if( inputPos == ll.getLength()+1 )	
		ll.insert(inputPos, cityNode);
}

void MedicalExecutive::split(const string& s, char delimiter, vector<string>& elems)
{
	stringstream ss;
	ss.str(s);
	string item;
	// get characters from ss and stores them in item until delimiter is reached or \n
	while( getline(ss, item, delimiter) ) {
		elems.push_back( item );
	}
}
