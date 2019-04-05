/**
*	@file : Dice.cpp
*	@author :  John Gibbons
*	@date : 2014.01.29
*	Purpose: Implementation of Dice Class
*/

#include "Dice.h"

Dice::Dice() 
{ 
	this->m_numSides = 6;
	/** initialize random seed: */
	srand (time(NULL));
}


Dice::Dice(int numSides)
{
	this->m_numSides = numSides;
	/** initialize random seed: */
	srand (time(NULL));
}


int Dice::getNumSides()
{
	return(this->m_numSides);
}

int Dice::roll()
{
	
	/** Get back a pseudo-random number */
	return(rand()%m_numSides + 1);
}

