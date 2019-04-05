/*	File Name: main.cpp
	Author: Henry C. Nguyen
        KUID: 2465007
	Email Address: henrynguyen@ku.edu
	Homework Assignment Number: Lab 1 
	Description: This is the first lab of EECS 268 which obtains user input for pattern type and size and outputs the desired pattern using said parameters.
	Last Changed: January 31st, 2014
*/
#include <iostream> 

int main(int argc, char** argv)
{
	//Prompt user to obtain pattern design
	int pattern_design = 0;
	std::cout << "Choose one of the following patterns by typing the corresponding number:\n1)\tGrid\n2)\tChecker Board\n3)\tReverse Diagonal\n";
	while(pattern_design < 1 || pattern_design > 3) //Catches user input error
	{
		std::cin >> pattern_design;
		if(pattern_design < 1 || pattern_design > 3)
		{
			std::cout << "\nError.\n";
		}
	}

	//Prompt user to obtain pattern size
	int pattern_size = 0;
	std::cout << "\nInput a size (must be larger than 1):\n";
	while(pattern_size < 2) //Catches user input error
	{
		std::cin >> pattern_size;
		if(pattern_size < 2)
		{
			std::cout << "\nError.\n";
		}
	}
	
	//Output desired pattern using user input parameters
	if(pattern_design == 1)
	{
		//Outputs a Grid pattern
		for(int i = 0; i < pattern_size; i++)
		{
			std::cout << "\n";
			for(int j = 0; j < pattern_size; j++)
			{
				std::cout << "*";
			}
		}
	}
	else if(pattern_design == 2)
	{
		//Outputs a Checkerboard pattern
		for(int i = 0; i < pattern_size; i++)
		{
			std::cout << "\n";
			for(int j = 0; j < pattern_size; j++)
			{
				if(i%2 == 0) 	//Even Rows
				{
					if(j%2 == 0) 	//Even Column
					{
						std::cout << "*";
					}
					else		//Odd Column
					{
						std::cout << " ";
					}
				}
				else		//Odd Rows
				{
					if(j%2 == 0)	//Even Column
					{
						std::cout << " ";
					}
					else		//Odd Column
					{
						std::cout << "*";
					}
				}
			}
		}
	}
	else
	{
		//Outputs a Reverse Diagonal Pattern
		for(int i = 0; i < pattern_size; i++)
		{
			std::cout << "\n";
			for(int j = 1; j <= pattern_size; j++)
			{
				if(j == (pattern_size - i))
				{
					std::cout << "*";
				}
				else
				{
					std::cout << " ";
				}
			}
		}
	}

	//Breaks last line for preference
	std::cout << "\n";
	return 0;
}
