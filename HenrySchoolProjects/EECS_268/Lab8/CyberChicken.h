//Filename: CyberChicken.h
//Description: Class declarations for CyberChicken class
//Assignment: EECS 268 Lab 8
//Author: Henry C. Nguyen
//Email: h724n828@ku.edu
//Date: 4-18-2014
//
//
#ifndef CYBERCHICKEN_H
#define CYBERCHICKEN_H

#include "FarmAnimal.h"
#include "Chicken.h"

class CyberChicken : public Chicken {
public:
	//@pre none
	//@post initializes member variables
	//@return none
	CyberChicken();

	//@pre m_eggs is initialized
	//@post none
	//@return value of m_eggs
	int getCyberEggs() const;

	//@pre m_eggs is initialized
	//@post sets m_eggs to parameter value
	//@return none
	void setCyberEggs(int eggs);
};

#endif
