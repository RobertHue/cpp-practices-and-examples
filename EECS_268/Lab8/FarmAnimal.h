//Filename: FarmAnimal.h
//Description: Class declarations for FarmAnimal class
//Assignment: EECS 268 Lab 7
//Author: Henry C. Nguyen
//Email: h724n828@ku.edu
//Date: 4-11-2014
//

#ifndef FARMANIMAL_H
#define FARMANIMAL_H

#include <string>

class FarmAnimal {
protected:
	std::string m_name;
	std::string m_sound;

public:
	//@pre none
	//@post initializes member variables
	//@return none
	FarmAnimal();

	//@pre m_name must be initialized
	//@post none
	//@return value of m_name
	std::string getName() const;

	//@pre none
	//@post sets m_name as parameter value
	//@return none
	void setName(std::string name);

	//@pre m_sound must be initialized
	//@post none
	//@return value of m_sound
	std::string getSound() const;

	//@pre none
	//@post sets m_sound as parameter value
	//@return none
	void setSound(std::string sound);
};

#endif
