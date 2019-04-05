//Filename: main.cpp
//Assignment: EECS 268 Lab 5
//Author: Henry C. Nguyen
//Description: File serves as an entry point for the program for
//declaration, initialization, and calls
//Date: 3-7-14
//Email: h724n828@ku.edu
//
#include <iostream>
#include "Node.h"
#include "BinarySearchTree.h"

int main(int argc, char * argv[])
{
	BinarySearchTree<int> numTree;
	int userNum=0;
	char quit='n';
	
	while(quit != 'y')
	{
		std::cout << "Input a number to put in the tree: ";
		std::cin >> userNum;		
		numTree.add(userNum);
		std::cout << "Done adding numbers? (y/n): ";
		std::cin >> quit;		
	}	

	std::cout << "\nTree currently has the following values: " << std::endl;	
	numTree.printTree();
	std::cout << "\nHere are sorted values: " << std::endl;	
	numTree.sortedPrint();
	std::cout << "\n\n";

	quit = 'n';

	while(quit != 'y')
	{
		std::cout << "Input a number to search for in the tree: ";
		std::cin >> userNum;		
		if( numTree.search(userNum) != nullptr )
		{
			std::cout << userNum << " is in the tree!" << std::endl;		
		}
		else
		{
			std::cout << "Sorry, " << userNum << " was not in the tree" << std::endl;
		}
		std::cout << "Done searching numbers? (y/n): ";
		std::cin >> quit;
	}

	std::cout << "\nGoodbye!" << std::endl;
	
	return(0);
}
