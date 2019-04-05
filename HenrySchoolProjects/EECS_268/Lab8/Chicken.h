//Filename: Chicken.h
//Description: Class declarations for Chicken class
//Assignment: EECS 268 Lab 8
//Author: Henry C. Nguyen
//Email: h724n828@ku.edu
//Date: 4-18-2014
//

#ifndef CHICKEN_H
#define CHICKEN_H

#include "FarmAnimal.h"

class Chicken : public FarmAnimal {
protected:
	//@pre m_eggs is initialized
	//@post none
	//@return value of m_eggs
	int getEggs() const;

	//@pre parameter value matches argument
	//@post sets value of m_eggs to parameter value
	//@return none
	void setEggs(int eggs);
	
	//member variable
	int m_eggs;
public:

	//@pre none
	//@post initializes member variables
	//@return none
	Chicken();
}; 

#endif
