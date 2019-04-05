//Filename: AnimalPen.h
//Description: Class declarations for AnimalPen class
//Assignment: EECS 268 Lab 8
//Author: Henry C. Nguyen
//Email: h724n828@ku.edu
//Date: 4-18-2014
//

#ifndef ANIMALPEN_H
#define ANIMALPEN_H

#include <stack>
#include "FarmAnimal.h"

class AnimalPen : public std::stack<FarmAnimal*> {
public:

	//@pre none
	//@post none
	//@return none
	AnimalPen();

	//@pre stack is initialized
	//@post deconstructs stack
	//@return none
	~AnimalPen();

	//@pre stack is initialized
	//@post adds parameter address to stack
	//@return none
	void addAnimal(FarmAnimal* animal);

	//@pre stack is initialized
	//@post none
	//@return top() value of the stack
	FarmAnimal* peakAtNextAnimal();

	//@pre stack is initialized and is not empty
	//@post pops off an element from the stack
	//@return none
	void releaseAnimal();

	//@pre stack is initialized
	//@post none
	//@return status if stack is empty or occupied
	bool isPenEmpty();
};

#endif
