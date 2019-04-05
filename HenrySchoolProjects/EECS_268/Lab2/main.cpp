#include <iostream>
#include <string>
#include "Pokemon.h"
#include "Dice.h"

int main(int argc, char* argv[])
{
	Pokemon player1;
	std::cout << "Player 1, build your Pokemon!\n";
	player1.userBuild();

	Pokemon player2;
	std::cout << "Player 2, build your Pokemon!\n";
	player2.userBuild();

	
	
	return 0;
}
