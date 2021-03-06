#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>
#include "Dice.h"

class Pokemon
{
	public:
	Pokemon();
	bool attack(Pokemon& opponent);
	void userBuild();

	//Get methods
	std::string getName();
	int getHP();
	int getAttackLevel();
	int getDefense();

	//Set methods
	void setName(std::string iName);
	void setHP(int iHP);
	void setAttackLevel(int iAttackLevel);
	void setDefense(int iDefense);

	private:
	std::string name;
	int hp;
	int attackLevel;
	int defense;
	Dice d20;
	Dice d6;
};

#endif
