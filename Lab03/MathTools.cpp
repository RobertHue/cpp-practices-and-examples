#include "MathTools.h"

// Custom Exception Classes:
#include <exception>
#include "NegativeDiscriminant.h"
#include "NoIntersection.h"
#include "CannotDetermineRoomDimensions.h"

#include <cmath>	// for sqrt
#include <iostream>	// for cout
using namespace std;

/// @brief:	method to get the solution (here: x) to the equation: 	a*x²+b*x+c = 0
/// @return:	the number of roots found (1 if the discriminant is zero; 2 otherwhise)
int MathTools::solveQuadratic(double a, double b, double c, double roots[])
		throw (NegativeDiscriminant)
{
	double D;	// the discriminant; can be <0 =0 or >0
	D = b*b-4*a*c;
	
	if( D < 0 )		// D < 0 => no solution of the equation if D<0
	{
		NegativeDiscriminant negDiscriminantException;
		throw negDiscriminantException;
	}
	else if( D > 0 )	// D > 0 => 2 solutions to equation
	{
		double rootOfD = sqrt(D);
		roots[0] = (-b+rootOfD) / (2*a);
		roots[1] = (-b-rootOfD) / (2*a);
		return 2;	
	}
	else 	// D == 0 => 1 solutions to equation
	{
		roots[0] = -b / (2*a);
		roots[1] = roots[0];
		return 1;
	}
}


/// @return the number of roots found (1 if the discriminant is zero; 2 otherwise)
int MathTools::intersectLineUnitCircle(double d, double e, double f, double xy[2][2])
		throw (NoIntersection)
{
	double roots[2];
	int numOfSolutions;
	try
	{
		numOfSolutions = solveQuadratic( d*d+e*e, 2*e*f, f*f-d*d, roots);
	} catch (exception& e) {	// catch the exception objects by reference (&) => this also catches derived from exception...
		cout << e.what() << endl;
		NegativeDiscriminant noIntersectionException;
		throw noIntersectionException;
	}
	
	// input the roots aka the y coordinates of the 1 or 2 intersections into the line equation:
	double x1 = (-e*roots[0]-f) / d;
	xy[0][0] = x1;
	xy[0][1] = roots[0];
	
	if( numOfSolutions == 2 ) 
	{
		double x2 = (-e*roots[1]-f) / d;
		xy[1][0] = x2;
		xy[1][1] = roots[1];
	}
	 
	return numOfSolutions;
}


void MathTools::roomDimensions(double Area, double Extra, double minRequiredLength,
		double& width, double& length) throw (CannotDetermineRoomDimensions)
{
	CannotDetermineRoomDimensions cannotDetermineRoomDimException;
	double roots[2];
	int numberOfSolutions;
	try
	{
		numberOfSolutions = solveQuadratic ( 1, Extra, -Area, roots );
		cout << roots[0] << endl;   
	} 
	catch (exception& e)
	{
		cout << e.what() << endl;
		throw cannotDetermineRoomDimException;
	}
	
	length = roots[0];
	if( length < minRequiredLength )  throw cannotDetermineRoomDimException;
	width = length + Extra;
}
