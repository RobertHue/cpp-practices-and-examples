#ifndef VOTERREGISTRATIONRECORD_H
#define VOTERREGISTRATIONRECORD_H

#include <string>
using namespace std;

// @brief	this class describes the members and methods of
//			an Voter object
class  VoterRegistrationRecord
{
private:
	string 	m_firstName;
	string 	m_lastName;
	int 	m_age;
	string 	m_affiliation;
	
public:
	// @brief	default constructor
	VoterRegistrationRecord() : 
		m_firstName(""),
		m_lastName(""),
		m_age(0),
		m_affiliation("")
	{}
	// @brief	copy assignment constructor
	VoterRegistrationRecord(
		string firstName, 
		string lastName, 
		int age, 
		string affiliation
	) : 
		m_firstName(firstName),
		m_lastName(lastName),
		m_age(age),
		m_affiliation(affiliation)
	{}
	
	// @brief	getters
	string 	getFirstName() const;
	string 	getLastName() const;
	int 	getAge() const;
	string 	getAffiliation() const;
};

#endif
