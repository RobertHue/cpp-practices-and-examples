//Filename: main.cpp
//Author: Henry C. Nguyen
//Assignment: EECS 268 Lab 3
//Description: File serves as an entry point for program to run properly and utilizese StackOfBoxes and Box classes to store and obtain desired information
//Date: 2-27-14
//Email: h724n828@ku.edu
//
#include <iostream>
#include "StackOfBoxes.h"

int main(int argc, char* argv[])
{
	//Create new stack
	StackOfBoxes myStack;
	//Locally create a variable to handle stack size at time of request
	int sizeOfStack;

	//Checks if stack is empty using isEmpty() method	
	std::cout << "Is the stack empty?" << std::endl;
	if(myStack.isEmpty())
	{
		std::cout << "Yes the stack is empty. I'm being honest to my knowledge!" << std::endl;
		sizeOfStack = 0;
	}
	else
	{
		std::cout << "Uh. Well. The stack isn't empty..." << std::endl;
	}

	std::cout << "Building Stack..." << std::endl;
	//Stores 10 values where value == (current_increment * 5);
	for(int i = 0; i < 10; i++)
	{
		//States what increment loop is on and what value is stored
		std::cout << "[Box:" << i << "] <= Value:" << (i*5) << std::endl;
		myStack.push(i * 5);	
	}
	std::cout << "Stack built." << std::endl;

	//Checks if stack is not empty after building stack (To test isEmpty() method)
	std::cout << "So is the stack still empty?" << std::endl;
	if(!myStack.isEmpty())
	{
		std::cout << "Dude, the stack is not empty. We just built it successfully." << std::endl;
	}
	else
	{
		std::cout << "What? Where'd the boxes go? The stack is empty!" << std::endl;
	}

	//Request stack size
	sizeOfStack = myStack.size();

	//State what the stack size is
	std::cout << "There are " << sizeOfStack << " items on the stack" << std::endl;

	//Pop the entire stack off and display the values of each box at time of popping.
	for(int i = 0; i < sizeOfStack; i++)
	{
		std::cout << "Popping the top: " << myStack.pop() << std::endl;
	}

	//End Program
	return 0;
}
