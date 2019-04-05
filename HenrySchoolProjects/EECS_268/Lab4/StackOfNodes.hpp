//Filename: StackOfNodes.hpp
//Author: Henry C. Nguyen
//Assignment: EECS 268 Lab 4
//Description: File contains the method descriptions of the StackOfNodes class
//Date: 2-28-14
//Email: h724n828@ku.edu
//
#include "StackOfNodes.h"

//Default Constructor
//Creates and initializes member variables of StackOfNodes class in template type
template<typename T>
StackOfNodes<T>::StackOfNodes()
{
	m_top = nullptr;
	m_size = 0;
}

//Returns a boolean describing if the stack is empty or not
template<typename T>
bool StackOfNodes<T>::isEmpty() const
{
	//Returns true if there are 0 nodes in the stack
	if(m_size == 0)
	{
		return true;
	}
	return false;
}

//Returns the amount of nodes within the stack as an integer
template<typename T>
int StackOfNodes<T>::size() const
{
	return m_size;
}

//Pushes on a template typed Node with input parameter  on top of the stack
template<typename T>
void StackOfNodes<T>::push(T value)
{
	//Creates a new node containing the value and previous address 
	Node<T>* newNode = new Node<T>(value, m_top);
	
	//Sets new top to address of new node
	m_top = newNode;

	//Increment m_size to reflect new stack size
	m_size++;
}

//Removes topmost template typed Node and returns value of the node as the
//same template type
template<typename T>
T StackOfNodes<T>::pop()
{
	//Creates a pointer pointing to the topmost node
	Node<T>* poppedNode = m_top;
	//Obtains and temporarily stores value of topmost node
	T poppedValue = m_top->getValue();
	//Sets the new top to address under topmost node
	m_top =	m_top->getPrevious();
	//Delete topmost node
	delete poppedNode;
	//Return value of popped node
	return poppedValue;
}
