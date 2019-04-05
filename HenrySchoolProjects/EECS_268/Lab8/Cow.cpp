//Filename: Cow.cpp
//Description: Class definitions for Cow
//Assignment: EECS 268 Lab 8
//Author: Henry C. Nguyen
//Email: h724n828@ku.edu
//Date: 4-17-2014
//

#include "Cow.h"

Cow::Cow() {
	setName("Cow");
	setSound("Moo");
}

double Cow::getMilkProduced() const {
	return m_milkProduced;
}

void Cow::setMilkProduced(double gallons) {
	if(gallons > 0) {
		m_milkProduced = gallons;
	}
	else {
		m_milkProduced = 0;
	}
}
