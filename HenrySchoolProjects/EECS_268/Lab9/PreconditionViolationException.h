//Filename: PreconditionViolationException.h
//Description: Definitions for PreconditionViolationException class
//Assignment: EECS 268 Lab 9
//Author: Henry C. Nguyen
//Email: h724n828@ku.edu
//Date: 5-1-2014

#ifndef PRECONDITIONVIOLATIONEXCEPTION_H
#define PRECONDITIONVIOLATIONEXCEPTION_H

#include <stdexcept>

class PreconditionViolationException : public std::runtime_error
{
public:
	//@pre none
	//@post passes an exception message to std::runtime_error constructor
	//@return none
	PreconditionViolationException(const char* message) : std::runtime_error(message) { };	
};

#endif
