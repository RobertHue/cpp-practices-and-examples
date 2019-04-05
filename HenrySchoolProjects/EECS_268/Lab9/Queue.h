//Filename: Queue.h
//Description: Definitions for Queue class
//Assignment: EECS 268 Lab 9
//Author: Henry C. Nguyen
//Email: h724n828@ku.edu
//Date: 5-1-2014
//

#ifndef QUEUE_H
#define QUEUE_H

#include "QueueInterface.h"
#include "Node.h"


template<typename T>
class Queue : public QueueInterface<T>
{
public:
	//@pre none
	//@post initializes member variables
	//@return none
	Queue();
	
	//@pre none
	//@post clears class related heap memory
	//@return none
	~Queue();

	//@pre none
	//@post none
	//@return queue emptiness status
	bool isEmpty() const;

	//@pre parameter value matches argument type
	//@post adds a new node entry with parameter value
	//@return none
	void enqueue(const T newEntry);

	//@pre none
	//@post removes front of the queue and frees heap memory
	//@return aftermath front of queue value
	T dequeue() throw(PreconditionViolationException);

	//@pre none
	//@post none
	//@return current front queue value
	T peekFront() const throw(PreconditionViolationException);

	//@pre none
	//@post none
	//@return size of queue
	int size() const;

private:
	//Class member variables
	Node<T>* m_front;
	
	int m_size;
};

#include "Queue.hpp"
#endif
