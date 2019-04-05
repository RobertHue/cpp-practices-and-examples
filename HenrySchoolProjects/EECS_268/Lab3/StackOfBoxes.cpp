//Filename: StackOfBoxes.cpp
//Author: Henry C. Nguyen
//Assignment: EECS 268 Lab 3
//Description: File contains essential methods for StackOfBoxes class
//Date: 2-27-14
//Email: h724n828@ku.edu
//
#include "StackOfBoxes.h"

//Default Stack Constructor
StackOfBoxes::StackOfBoxes()
{
	m_top = nullptr;
	m_size = 0;
}

//Returns true if stack is empty, otherwise false
bool StackOfBoxes::isEmpty() const
{
	if(m_size == 0)
	{
		return true;
	}
	return false;
}

//Returns the size of the stack as integer
int StackOfBoxes::size() const
{
	return m_size;
}

//Creates a new Box instance with input value and pushes on top of stack
void StackOfBoxes::push(int value)
{
	//Uses constructor parameters to set previous pointer to pre-changed m_top
	//and stores value
	Box* newBox = new Box(value, m_top);
	//Set newBox as top of stack
	m_top = newBox;
	//Increment stack size to reflect changes
	m_size++;
}


//Removes the top-most instance of Box on the stack
int StackOfBoxes::pop()
{
	//Create a temporary pointer to top of stack
	Box* popped_box = m_top;
	//Obtain value of top of stack
	int popped_value = m_top->getValue();
	//Set new top as the box instance before top
	m_top = m_top->getPrevious();
	//Decrement stack size to reflect changes
	m_size--;

	//Delete popped object pointer
	delete popped_box;
	return popped_value;
}
