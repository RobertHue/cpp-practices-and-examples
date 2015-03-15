#include "Pokemon.h"
 
Pokemon::Pokemon()
{
	hp = 0;
	attackLevel = 0;
	defense = 0;
	name = "";
	d20 = Dice(20);
	d6 = Dice(6);
}

bool Pokemon::attack(Pokemon& opponent)
{
	int attackBonus = d20.roll();
	int defenseBonus = d20.roll();

	std::cout << name << " rolls an attack bonus of " << attackBonus + "\n";
	std::cout << opponent.name << " rolls a defense bonus of " << defenseBonus + "\n"; 

	if( (attackLevel + attackBonus) > (opponent.defense + defenseBonus) )
	{
		std::cout << "The attack hits dealing 3-D6 damage!\n The rolls are ";

		int damage = 0;
		for(int i=0;i<3;i++)
		{
			int roll = d6.roll();
			if(i < 2)
			{
				std::cout << roll << ", ";
			}
			else
			{
				std::cout << "and " << roll << " totalling: ";
			}
			damage+=roll;
		}
		std::cout << damage << " damage!\n";
		opponent.hp-=damage;
		if(opponent.hp > 0)
		{
			std::cout << opponent.name << " has " << opponent.hp << " hit points left\n";
		}
		else
		{
			std::cout << opponent.name << " has been defeated!\n";
			return true;
		}
	}
	else
	{
		std::cout << "The attack missed!\n";
	}

	return false;
}

void Pokemon::userBuild()
{
	std::cout << "=====================\nPlease name your pokemon: ";
	while(name.length() <= 0)
	{		
		std::cin >> name;
		if(name.length() <= 0)
		{
			std::cout << "\n\nSorry the name is too short: ";
		}
	}

	std::cout << "\nHow many hit points will it have? (1-50): ";
	while(hp < 1 || hp > 50)
	{
		std::cin >> hp;
		std::cin;
		if(hp < 1 || hp > 50)
		{
			std::cout << "\n\nSorry. The hit points must be between 1 and 50: ";
		}
	}

	std::cout << "\nSplit fifty points between attack level and defense level\nEnter your attack level (1-49): ";
	int skillPoints = 50;

	while(attackLevel < 1 || attackLevel > 49)
	{
		std::cin >> attackLevel;
		if(attackLevel < 1 || attackLevel > 49)
		{
			std::cout << "\nSorry. The attack level must be between 1 and 49: ";
		}
	}

	skillPoints-=attackLevel;

	std::cout << "\nEnter your defense level (1-" << skillPoints << "): ";
	while(defense < 1 || defense > skillPoints)
	{
		std::cin >> defense;
		if(defense < 1 || defense > skillPoints)
		{
			std::cout << "\nSorry. The defense level must be between 1 and " << skillPoints << ": ";
		}
	}
	std::cout << "\n";
}

//Get methods
std::string Pokemon::getName()
{
	return name;
}

int Pokemon::getHP()
{
	return hp;
}

int Pokemon::getAttackLevel()
{
	return attackLevel;
}
int Pokemon::getDefense()
{
	return defense;
}

//Set methods
void Pokemon::setName(std::string iName)
{
	name = iName;
}
void Pokemon::setHP(int iHP)
{
	hp = iHP;
}
void Pokemon::setAttackLevel(int iAttackLevel)
{
	attackLevel = iAttackLevel;
}
void Pokemon::setDefense(int iDefense)
{
	defense = iDefense;
}


