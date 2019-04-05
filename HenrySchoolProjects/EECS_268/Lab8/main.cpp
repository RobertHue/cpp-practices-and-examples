//Filename: main.cpp
//Description: Entry point for lab8 program
//Assignment: EECS 268 Lab 8
//Author: Henry C. Nguyen
//Email: h724n828@ku.edu
//Date: 4-18-2014

#include <iostream>
#include <string>
#include "FarmAnimal.h"
#include "Cow.h"
#include "Chicken.h"
#include "CyberChicken.h"
#include "AnimalPen.h"

void goodbyeMessage(const FarmAnimal& animal)
{
	std::cout << "Upon release the " << animal.getName() << " said " << animal.getSound() << std::endl;
}

int main(int argc, char* argv[])
{
	AnimalPen myAnimalPen;
	int choice = 0;
	char finished = 'n';

	//Obtains user input for element set up and addition to specialized AnimalPen stack
	while(finished != 'y')
	{
		std::cout << "Selected an animal to add to the pen:" << std::endl
		<< "1.) Cow (produces milk)" << std::endl << "2.) Chicken (cannot lay eggs)" <<
		std::endl << "3.) Cyber Chicken (seems dangerous, but lays eggs)" << std::endl
		<< "-------------------------------------------------------------" << std::endl << std::endl;

		std::cin >> choice;
		if(choice > 0 && choice < 4) {
			if(choice == 1) {
				Cow* newCow = new Cow();
				std::cout << "How many gallons of milk did this cow produce?";
				double milk = 0.0;
				std::cin >> milk;
				newCow->setMilkProduced(milk);
				myAnimalPen.addAnimal(newCow);
			} else if(choice == 2) {
				Chicken* newChicken = new Chicken();
				std::cout << "Add an eggless chicken to the pen? OK. You're the boss."
				<< std::endl;
				myAnimalPen.addAnimal(newChicken);
			} else {
				CyberChicken* newCyberChicken = new CyberChicken();
				std::cout << "How many eggs did this cyber chicken produce?: ";
				int eggs = 0;
				std::cin >> eggs;
				newCyberChicken->setCyberEggs(eggs);
				myAnimalPen.addAnimal(newCyberChicken);
			}
		}
		else {
			std::cout << std::endl << "This is not a valid choice. Please choose a proper choice!"
			<< std::endl;
		}

		std::cout << std::endl << "Done adding animals? (y/n): ";
		std::cin >> finished;
	}

	//pops off animalPen stack and displays all information related
	while(!myAnimalPen.isPenEmpty())
	{
		FarmAnimal* nextAnimal = myAnimalPen.peakAtNextAnimal();
		std::string animalName = nextAnimal->getName();
	
		if(animalName == "Cow") {
			double milkProduced = static_cast<Cow*>(nextAnimal)->getMilkProduced();
			std::cout << "This " << animalName << " produced " << milkProduced
			<< " gallons of milk" << std::endl;
		}
		else if(animalName == "Chicken") {
			std::cout << animalName << " is unable to lay eggs. Perhaps cybernetic implants will help?"
			<< std::endl;

		} else if(animalName == "CyberChicken") {
			int cyberEggs = static_cast<CyberChicken*>(nextAnimal)->getCyberEggs();
			std::cout << "This " << animalName << " laid " << cyberEggs <<
			" cyber eggs. Humanity is in trouble." << std::endl;
		}

		goodbyeMessage(*nextAnimal);		
		myAnimalPen.releaseAnimal();
	}
	return 0;
}
