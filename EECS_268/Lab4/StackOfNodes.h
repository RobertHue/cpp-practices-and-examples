//Filename: StackOfNodes.h
//Author: Henry C. Nguyen
//Assignment: EECS 268 Lab 4
//Description: Header file for StackOfNodes class which contains prototypes for methods
//and member variables of the class
//Date: 2-28-14
//Email: h724n828@ku.edu
//
#ifndef STACKOFNODES_H
#define STACKOFNODES_H

#include "Node.h"

template<typename T>
class StackOfNodes {
	public:
	//Class Methods
	//=============
	//Default Constructor
	//@pre none
	//@post Creates and initializes member variables
	//@return none
	StackOfNodes();

	//@pre Member variables must be initialized
	//@post none
	//@return Boolean describing if there are nodes contained in the stack or not
	bool isEmpty() const;

	//@pre Member variables must be initialized
	//@post none
	//@return Integer that reflects the size of the stack (number of nodes within stack)
	int size() const;

	//@pre value must match type T (parameter input type)
	//@post places type T node on top of the stack and reflects changes on stack
	//member variables
	//@return none
	void push(T value);

	//@pre Stack must not be empty
	//@post Pops of topmost node, returns the type T value, deletes the node,
	//and reflects changes in stack member variables
	//@return Type T value of popped node
	T pop();

	private:
	//Member Variables
	//================
	//Contains the address of the top-most node within the stack
	Node<T>* m_top;

	//Reflects the number of nodes contained within the stack
	int m_size;
};

#include "StackOfNodes.hpp"
#endif
