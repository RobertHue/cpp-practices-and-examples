//Filename: FarmAnimal.cpp
//Description: Class method definitions for FarmAnimal class
//Assignment: EECS 268 Lab 8
//Author: Henry C. Nguyen
//Email: h724n828@ku.edu
//Date: 4-11-2014
//

#include "FarmAnimal.h"

FarmAnimal::FarmAnimal() {
	m_name = "unset";
	m_sound = "unset";
}

std::string FarmAnimal::getName() const {
	return m_name;
}

void FarmAnimal::setName(std::string name) {
	m_name = name;
}

std::string FarmAnimal::getSound() const {
	return m_sound;
}

void FarmAnimal::setSound(std::string sound) {
	m_sound = sound;
}

