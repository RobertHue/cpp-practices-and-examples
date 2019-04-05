 /**
*	@file main.cpp
*	@author Robert Hümmer
*	@date 17.12.2016
*	@brief The file containing the main entry point of the program
*/
#include "MedicalExecutive.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char * argv[])
{
	MedicalExecutive exec(argv[1]);
	exec.run();
	return 0;
}
