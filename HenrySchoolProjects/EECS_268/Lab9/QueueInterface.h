//Filename: QueueInterface.h
//Description: Header file for QueueInterface class
//Assignment: EECS 268 Lab 9
//Author: Henry C. Nguyen
//Email: h724n828@ku.edu
//Date: 5-1-2014

#ifndef QUEUEINTERFACE_H
#define QUEUEINTERFACE_H

#include "PreconditionViolationException.h"

template<typename T>
class QueueInterface 
{
public:
	//@pre none
	//@post none
	//@return none
	virtual ~QueueInterface() {};
	
	//@pre none
	//@Post none
	//@return none
	virtual bool isEmpty() const = 0;

	//@pre none
	//@post none
	//@return none
	virtual void enqueue(const T newEntry) = 0;

	//@pre none
	//@post none
	//@return none
	virtual T dequeue() throw(PreconditionViolationException) = 0;

	//@pre none
	//@post none
	//@return none
	virtual T peekFront() const throw(PreconditionViolationException) = 0;

	//@pre none
	//@post none
	//@return none
	virtual int size() const = 0;		
};

#endif
