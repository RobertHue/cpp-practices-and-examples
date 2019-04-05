//Filename: Node.h
//Assignment: EECS 268 Lab 5
//Author: Henry C. Nguyen
//Description: File serves as header definition for Node class
//Date: 3-7-14
//Email: h724n828@ku.edu
//
#ifndef NODE_H
#define NODE_H

template<typename T>
class Node {
	private:
	//Class Member Variables
	//Points to left subtree
	Node<T> * m_left;
	
	//Points to right subtree
	Node<T> * m_right;
	
	//Stores Node Value 	
	T m_value;

	public:
	//Default Constructor
	//@pre none
	//@post initializes class members
	//@return none
	Node();
	
	//Get Methods for Class Members
	//=============================
	//@pre none
	//@post none
	//@return m_left
	Node<T> * getLeft();
	
	//@pre none
	//@post none
	//@return m_right
	Node<T> * getRight();

	//@pre none
	//@post none
	//@return m_value
	T getValue();

	//Set Methods for Class Members
	//=============================
	//@pre m_left is initialized
	//@post assigns parameter value to m_left
	//@return none
	void setLeft(Node<T> * left);
	
	//@pre m_right is initialized
	//@post assigns parameter value to m_right
	//@return none
	void setRight(Node<T> * right);

	//@pre m_value is initialized
	//@post assigns parameter value to m_value
	//@return none
	void setValue(T value);
};

#include "Node.hpp"

#endif
