#include "AnimalPen.h"
#include <iostream>
AnimalPen::AnimalPen() {
	
}

AnimalPen::~AnimalPen() {
	while(!isPenEmpty()) {
		releaseAnimal();
	}
}

void AnimalPen::addAnimal(FarmAnimal* animal) {
	std::stack<FarmAnimal*>::push(animal);
}

FarmAnimal* AnimalPen::peakAtNextAnimal() {
	return std::stack<FarmAnimal*>::top();
}

void AnimalPen::releaseAnimal() {
	delete std::stack<FarmAnimal*>::top();
	std::stack<FarmAnimal*>::pop();
}

bool AnimalPen::isPenEmpty() {
	if((std::stack<FarmAnimal*>::empty()))
	{
		return true;
	}
	return false;
}


