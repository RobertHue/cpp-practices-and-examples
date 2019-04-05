//Filename: Chicken.h
//Description: Class deinfitions for Chicken class
//Assignment: EECS 268 Lab 8
//Author: Henry C. Nguyen
//Email: h724n828@ku.edu
//Date: 4-18-2014
//
#include "Chicken.h"

Chicken::Chicken() {
	setName("Chicken");
	setSound("Cluck");
}

int Chicken::getEggs() const {
	return m_eggs;
}

void Chicken::setEggs(int eggs) {
	m_eggs = eggs;
}
