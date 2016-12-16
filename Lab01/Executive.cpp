#include "Executive.h"
#include "VoterRegistrationRecord.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdexcept>	// throwing exception in case of no associated file to stream
#include <map>			// for counting the number of ppl in affiliation
#include <iterator>		// for iterating through the vector m_voters
using namespace std;


Executive::Executive(char * p_fileName)
{
	string line;
	int numOfRecordEntries, idx=0;
	
	// open the file to be read
	ifstream fileStream(p_fileName);
	
	// check if stream has associated file
	if( fileStream.is_open() == false )
	{	
		cout << "........................." << endl;
		throw runtime_error("unable to open file! \
							Please input file data into program!");
	}
	
	// read new line until eof
	while( getline(fileStream, line) ) 
	{
		// push the space-seperated line into vector "results"
		vector<string> results;
		istringstream iss(line);
		for(string s; iss >> s; )
			results.push_back(s);	
			
		
		if( results.size() == 1 )	// only one element in line
		{
			// read the number of records
			numOfRecordEntries = stoi( results[0] );
			
			// dynamically allocate array of VoterRegistrationRecord
			m_voters = vector<VoterRegistrationRecord>(numOfRecordEntries);
		}
		else 	// more elements in line
		{
			// coordinate the reading of the data into the array
			if( m_voters.size()!= 0 )
			{
				m_voters[idx++] = VoterRegistrationRecord(
										results.at(0),
										results.at(1),
										stoi(results.at(2)),
										results.at(3)  );
			}
		}
	}
	
	// close the file stream
	fileStream.close();
}
	
void Executive::run(void)
{
	int input; 
	do
	{
		cout << "1: Query last name" << endl;
		cout << "2: Query age range" << endl;
		cout << "3: Query affiliation" << endl;
		cout << "4: Report number of people with affiliation" << endl;
		cout << "5: Quit" << endl;
		cin >> input;
		cin.get();	// remove \n from cin
		
		switch(input)
		{  
			case 1:	// Query last name
			{  // <- are needed because name would be visible to case 2 otherwhise
				string name;
				cout << "Enter last name: ";
				cin >> name;
				cin.get();	// remove \n from cin
				
				// Search for last name:
				for(unsigned int i=0; i<m_voters.size(); ++i)
				{
					if( name.compare(m_voters[i].getLastName()) == 0 )
					{
						cout << "Record: " <<
							m_voters[i].getFirstName() << " " <<
							m_voters[i].getLastName() << "; " <<
							m_voters[i].getAge() << "; Registered as " <<
							m_voters[i].getAffiliation() << endl;
					} 
				}
				break;
			}
			case 2:	// Query age range
			{
				int ageLowerBound, ageUpperBound;
				cout << "Enter lower bound age: ";
				cin >> ageLowerBound;
				cin.get();	// remove \n from cin
				cout << "Enter upper bound age: ";
				cin >> ageUpperBound;
				cin.get();	// remove \n from cin
				
				// Search for age range:
				for(unsigned int i=0; i<m_voters.size(); ++i)
				{
					if( m_voters[i].getAge() >= ageLowerBound &&
						m_voters[i].getAge() <= ageUpperBound )
					{
						cout << "Record: " <<
							m_voters[i].getFirstName() << " " <<
							m_voters[i].getLastName() << "; " <<
							m_voters[i].getAge() << "; Registered as " <<
							m_voters[i].getAffiliation() << endl;
					} 
				}
				break;
			}
			case 3:	// Query affiliation
			{
				string affName;
				cout << "Enter affiliation: ";
				cin >> affName;
				cin.get();	// remove \n from cin
				
				// Search for affiliation:
				for(unsigned int i=0; i<m_voters.size(); ++i)
				{
					if( affName.compare(m_voters[i].getAffiliation()) == 0 )
					{
						cout << "Record: " <<
							m_voters[i].getFirstName() << " " <<
							m_voters[i].getLastName() << "; " <<
							m_voters[i].getAge() << "; Registered as " <<
							m_voters[i].getAffiliation() << endl;
					} 
				}
				break;
			}
			case 4:	// Report number of people with affiliation
			{
				// the number of people in aff gets stored in this Map:
				map<string,int> affilationToAmountOfPeopleMap;
				
				// count the number of people in affiliation:
				for( auto it = m_voters.cbegin(); it != m_voters.cend(); ++it )
				{
					string cur_aff = it->getAffiliation();
					
					affilationToAmountOfPeopleMap[ cur_aff ] =
						++affilationToAmountOfPeopleMap[ cur_aff ];
				}
				
				// print the number of ppl in each affiliation:
				for( auto it = affilationToAmountOfPeopleMap.cbegin(); 
						it != affilationToAmountOfPeopleMap.cend(); ++it )
				{
					cout << "[" << it->first << ":" << it->second << "]"<< endl;
				}
				break;
			}
			case 5:	// QUIT
			{
				break;
			}
			default:
			{
				cout << "Wrong inpt! Please try again" << endl;
			}
		}
	} while (input != 5);
	cout << "\nThanks for checking voter registrations!\nBye." << endl;
}
