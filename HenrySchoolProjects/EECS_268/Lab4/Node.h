//Filename: Node.h
//Author: Henry C. Nguyen
//Assignment: EECS 268 Lab 4
//Description: Header file for template Node class which contains prototypes
//for class methods and member variables
//Date: 2-28-14
//Email: h724n828@ku.edu
//
#ifndef NODE_H
#define NODE_H

template<typename T>
class Node {
	public:
	//Default Constructor
	//@pre none
	//@post Creates and initializes member variables
	//@return none
	Node();
	
	//Alternative Constructor
	//@pre type of input parameters must match type T
	//@post Creates and initializes member variables
	//@return none
	Node(T value, Node<T>* previous);

	//Alternative Constructor
	//@pre type of input parameter must match type T
	//@post Creates and initializes value member variable
	//@return none
	Node(T value);
	
	//Get Methods
	//===========
	//@pre none
	//@post none
	//@return value stored as template type
	T getValue();

	//@pre none;
	//@post none
	//@return address of previous linked Node<T>
	Node<T>* getPrevious();

	//Set Methods
	//===========
	//@pre input value must match template type T
	//@post sets node value to input
	//@return none
	void setValue(T value);

	//@pre input node address must match template type T
	//@post sets previous pointer to input address
	//@return none
	void setPrevious(Node<T>* previous);

	private:
	//Member Variables
	//================
	//Stores a linked address of previous matching  template type node
	Node<T>* m_previous;
	
	//Stores value of template type T
	T m_value;
};

#include "Node.hpp"
#endif
