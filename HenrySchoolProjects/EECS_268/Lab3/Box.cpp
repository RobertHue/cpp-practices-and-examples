//Filename: Box.cpp
//Author: Henry C. Nguyen
//Assignment EECS 268 Lab 3
//Description: File contains essential methods for Box class
//Date: 2-27-14
//Email: h724n828@ku.edu
//
#include "Box.h"


//Default Constructor class which initializes all member variable values
Box::Box()
{
	this->m_value = 0;
	//Sets m_previous pointer to requred C++11 nullptr address
	this->m_previous = nullptr;		
}

//Alternrative Constructor for value only input and null m_previous vlaue
Box::Box(int value)
{
	this->m_value = value;
	this->m_previous = nullptr;
}

//Alternative Constructor for both value and m_previous inputs
Box::Box(int value, Box* previous)
{
	this->m_value = value;
	this->m_previous = previous;
}

//Set Methods for member variables
void Box::setValue(int value)
{
	this->m_value = value;
}

void Box::setPrevious(Box* previous)
{
	this->m_previous = previous;
}

//Get Methods for member variables
int Box::getValue()
{
	return this->m_value;
}

Box* Box::getPrevious()
{
	//Returns address of previous object
	return this->m_previous;
}
