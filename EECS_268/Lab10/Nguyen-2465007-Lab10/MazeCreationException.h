//Filename: MazeCreationException.h
//Description: Declarations for MazeCreationException class
//Assignment: EECS 268 Lab 10
//Author: Henry C. Nguyen
//Email: h724n828@ku.edu
//Date: 5-7-2014
//

#ifndef MAZECREATIONEXCEPTION_H
#define MAZECREATIONEXCEPTION_H

#include <stdexcept>

class MazeCreationException : public std::runtime_error
{
public:
	//@pre none
	//@post pass exception
	//@return none
	MazeCreationException(const char* message) : std::runtime_error(message) { };
};

#endif
