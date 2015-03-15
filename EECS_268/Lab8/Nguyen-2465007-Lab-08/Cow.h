//Filename: Cow.h
//Description: Class declarations for Cow class
//Assignment: EECS 268 Lab 8
//Author: Henry C. Nguyen
//Email: h724n828@ku.edu
//Date: 4-11-2014
//

#ifndef COW_H
#define COW_H

#include "FarmAnimal.h"

class Cow : public FarmAnimal {
protected:
	double m_milkProduced;

public:
	//@pre none
	//@post initializes class members
	//@return none
	Cow();

	//@pre m_milkProduced is initialized
	//@post none
	//@return the value of m_milkProduced 
	double getMilkProduced() const;

	//@pre none
	//@post sets m_milkProduced to parameter value
	//@return none
	void setMilkProduced(double gallons);
};

#include "Cow.h"

#endif
