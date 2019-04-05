//Filename: main.cpp
//Author: Henry C. Nguyen
//Assignment: EECS 268 Lab 4
//Description: File serves as an entry point for the lab 4 program.
//It creates, initializes, and calls anything necessary to run the program properly.
//Date: 2-28-14
//Email: h724n828@ku.edu
//
#include <iostream>
#include <string>
#include "Node.h" //Template Node class
#include "StackOfNodes.h" //Template StackOfNodes class

int main(int argc, char* argv[])
{
	//Creates and initializes a stack for integer type
	StackOfNodes<int> myStack;
	//Initializes variable containing current stack size
	int sizeOfStack = myStack.size();

	//Tests isEmpty method for StackOfNodes class
	std::cout << "Stack has been created" << std::endl
		<< "Is the stack empty?" << std::endl;
	if(myStack.isEmpty())
	{
		std::cout << "Yes the stack is empty!" << std::endl;
	}
	else
	{
		std::cout << "No the stack is not empty." << std::endl;
	}

	//Builds stack with 10 nodes and stores value (i*5) accordingly to node increment
	std::cout << "Building stack..." << std::endl;
	for(int i = 1; i<=10; i++)
	{
		//States values being stored in which node
		std::cout << "[Node: " << (i-1) << "]<=Value: " << (i*5) << std::endl;
		//Calls push method to push node ontop of the stack
		myStack.push(i * 5);
	}
	std::cout << "Stack built." << std::endl
		<< "Is the built stack empty now?" << std::endl;

	//Tests isEmpty method again to see if it returns a different value
	if(!myStack.isEmpty())
	{
		//Update sizeOfStack variable with new current size of the stack
		sizeOfStack = myStack.size();
		std::cout << "No the stack is not empty!" << std::endl
			<< "There are " << sizeOfStack << " nodes on the stack" << std::endl;
	}
	else
	{
		std::cout << "Yes the stack is empty!" << std::endl;
	}
	
	//Pops all the nodes off of the stack and display the values being stored in each
	//node as its being popped.
	for(int i = 0; i < sizeOfStack; i++)
	{
		std::cout << "Popping the top: " << myStack.pop() << std::endl;
	}
	std::cout << "Stack popping completed and is now empty!" << std::endl;	

	//End Program
	return 0;
}
