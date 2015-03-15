//Filename: main.cpp
//Description: 
//Assignment: EECS 268 Lab 10
//Author: Henry C. Nguyen
//Email: h724n828@ku.edu
//Date: 5-7-2014

#include <iostream>
#include "MazeReader.h"

int main(int argc, char* argv[])
{
	std::cout << "The program " << argv[0] << " is now attempting to read " 
	<< argv[1] << std::endl;

	MazeReader mazeRead(argv[1]);		
	
	std::cout << "Calling getRows() and getCols() " <<
	mazeRead.getRows() << " " << mazeRead.getCols() << std::endl; 
	
	std::cout << "Calling getStartRow() and getStartCol() " <<
	mazeRead.getStartCol() << " " << mazeRead.getStartCol() << std::endl;

	return 0;
}
