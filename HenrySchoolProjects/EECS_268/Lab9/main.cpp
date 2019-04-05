//Filename: main.cpp
//Description: Entry point for lab8 program
//Assignment: EECS 268 Lab 9
//Author: Henry C. Nguyen
//Email: h724n828@ku.edu
//Date: 4-24-14

#include <stack>
#include <stdexcept>
#include <iostream>
#include "Queue.h"

template <typename T> void printQueue(QueueInterface<T>& q);

void printMenu();

int main(int argc, char* argv[])
{
	Queue<int> myQueue;
	int choice = 0;

	int j = 1;
	while(choice != 5)
	{
		printMenu();
		std::cin >> choice;
		try
		{
			if(choice == 1)
			{
				int number;
				std::cout << "Enter a number: ";
				std::cin >> number;
				myQueue.enqueue(number);
			}
			else if(choice == 2)
			{
				std::cout << "[" << myQueue.dequeue() << "]" << std::endl;
			}
			else if(choice == 3)
			{
				std::cout << "[" <<  myQueue.peekFront() << "]" << std::endl;
			}
			else if(choice == 4)
			{
				printQueue(myQueue);
			}
		}
		catch(std::exception e)
		{
			std::cout << e.what();
		}
	}
	return 0;
}

template <typename T>
void printQueue(QueueInterface<T>& q)
{
	std::cout << "Printing queue..." << std::endl;
	std::stack<T> temp;

	while(!q.isEmpty())
	{
		T value = q.peekFront();
		q.dequeue();
		temp.push(value);	
	}

	std::stack<T> reversetemp;
	while(!temp.empty())
	{
		reversetemp.push(temp.top());
		temp.pop();
	}

	while(!reversetemp.empty())
	{
		std::cout << "Printed Value: " << reversetemp.top() << std::endl;
		q.enqueue(reversetemp.top());
		reversetemp.pop();
	}
		
}

void printMenu()
{
	std::cout << "Select an action:\n1)\tEnqueue a number\n2)\tDequeue a  number\n3)\tPeak at front"
	<< "\n4)\tPrint the queue\n5)\tQuit\nEnter choice:" << std::endl;
}
