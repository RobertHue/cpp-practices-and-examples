//Filename: StackOfBoxes.h
//Author: Henry C. Nguyen
//Assignment: EECS 268 Lab 3
//Description: File is the header file for the StackOfBoxes class and contains prototypes for necessary class methods and members.
//Date: 2-27-14
//Email: h724n828@ku.edu
//
#ifndef STACKOFBOXES_H
#define STACKOFBOXES_H

#include "Box.h"

class StackOfBoxes {
	public:
		//Class Methods
		//Default Constructor
		//@pre none
		//@post Creates and initializes stack of boxes
		//@return Initialized StackOfBoxes
		StackOfBoxes();
		
		//Returns if stack is empty or not
		//@pre none
		//@post none
		//@returns emptiness status of the stack
		bool isEmpty() const;
		
		//Returns size data of stack
		//@pre none
		//@post none
		//@return the size of the stack
		int size() const;

		//Pushes on a new Box class with input value
		//@pre value must be an integer
		//@post adds a new box instance with desired value on top of stack
		//@return none
		void push(int value);

		//Pops off top box class and sets new top as previous box
		//@pre stack size must be > 0
		//@post removes top-most box
		//@returns value of removed box
		int pop();

	private:
		//Member Variables
		//Stores address to top-most box
		Box* m_top;

		//Stores stack size
		int m_size;
		
};

#endif
