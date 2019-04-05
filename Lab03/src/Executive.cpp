#include "Executive.h"

#include "MathToolsInterface.h"
#include "MathTools.h"

// Custom Exception Classes:
#include <exception>
#include "NegativeDiscriminant.h"
#include "NoIntersection.h"
#include "CannotDetermineRoomDimensions.h"

#include <iostream>
#include <limits>	// for streamsize

Executive::Executive() : mathTools()
{ 
}
	
void Executive::run()
{
	int choice; 
	do
	{
		try{
			std::cout << "################################################" << std::endl;
			std::cout << "Make a selection:" << std::endl;
			std::cout << "1) Enter A, B, C for a quadratic equation to be solved" << std::endl;
			std::cout << "2) Enter the d, e, f parameters for a line to be intersected with a unit circle" << std::endl;
			std::cout << "3) Enter Area, Extra, and minRequiredLength for a ballroom" << std::endl;
			std::cout << "4) Quit" << std::endl;
			std::cout << "Choice: ";
			std::cin >> choice;
			// recovering from bad user input:
			while( std::cin.fail() )
			{
				std::cin.clear();	// unset failbit
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	// skip bad input (ignore until \n)
				std::cout << "Sorry, your input did not seem to be an int. Please try again! " << std::endl;
				std::cout << "Choice: ";
				std::cin >> choice;
			}
			 
			switch(choice)
			{  
				case 1:	// quadratic equation
				{
					int a, b, c, numberOfSolutions;
					double roots[2];
					std::cout << "Please select a b and c" << std::endl;
					std::cout << "a: "; 	std::cin >> a;
					std::cout << "b: "; 	std::cin >> b;
					std::cout << "c: "; 	std::cin >> c;
					numberOfSolutions = mathTools.solveQuadratic(a,b,c,roots);
					std::cout << "There are " << numberOfSolutions << " solutions to the quadratic equation." << std::endl;
					std::cout << "Solution: " << roots[0] << ", 0)" << std::endl;
					if(numberOfSolutions==2)	std::cout << "Solution: (" << roots[1] << ", 0)" << std::endl;
					break;
				}
				case 2:	// intersection with unit circle
				{
					int d, e, f, numberOfSolutions;
					double xy[2][2];	// holds the two possible intersection points
					std::cout << "Please select d e and f" << std::endl;
					std::cout << "d: "; 	std::cin >> d;
					std::cout << "e: "; 	std::cin >> e;
					std::cout << "f: "; 	std::cin >> f;
					numberOfSolutions = mathTools.intersectLineUnitCircle(d,e,f,xy);
					std::cout << "There are " << "intersection(s) of the line with the circle." << std::endl;
					std::cout << "Solution 1: (" << xy[0][0] << " , "  << xy[0][1] << ")" << std::endl;
					if(numberOfSolutions==2)
						std::cout << "Solution 2: (" << xy[1][0] << " , "  << xy[1][1] << ")" << std::endl;
					break;
				}
				case 3:	// search for a ballroom
				{
					double area, extra, minRequired, width, length;
					std::cout << "Please select Area, Extra and minRequired for a ballroom" << std::endl;
					std::cout << "Area: "; 	std::cin >> area;
					std::cout << "Extra: "; 	std::cin >> extra;
					std::cout << "minRequired: "; 	std::cin >> minRequired;
					mathTools.roomDimensions(area, extra, minRequired, width, length);
					std::cout << "Perfect Ballroom with property of W=L+E:" << 
						"\nWidth: " << width << "\nLength: " << length << std::endl;
					break;
				}
				case 4:	// QUIT
				{
					break;
				}
				default:
				{
					std::cout << "Wrong inpt! Please try again" << std::endl;
				}
			}
		} 
		catch( std::exception& e )
		{
			std::cout << e.what() << std::endl;
		}
	} while (choice != 4);
	std::cout << "\nThanks for checking MathTools!\nBye." << std::endl;
}
