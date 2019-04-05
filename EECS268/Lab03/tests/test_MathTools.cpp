// Set Module name (prints at testing)
#define BOOST_TEST_MODULE "MathToolsInterface"

// Link to Boost
// #define BOOST_TEST_DYN_LINK

// Very IMPORTANT - include this after dyn_link and boost_test_module
#include <boost/test/unit_test.hpp>

// Custom Exception Classes:
#include <exception>
#include "NegativeDiscriminant.h"
#include "NoIntersection.h"
#include "CannotDetermineRoomDimensions.h"

// Modules to test
#include "MathToolsInterface.h"
#include "MathTools.h"

//-----------Tests follow ---------------------
BOOST_AUTO_TEST_CASE( solveQuadratic )
{
	MathTools mathTools;
	
	// check solveQuadratic
	double roots[2];
	int numOfSolutions;
	
	// D>0
	try
	{
		numOfSolutions = mathTools.solveQuadratic(-1,2,3, roots);
	} catch (std::exception& e) {
		BOOST_FAIL( e.what() );
	}
	BOOST_CHECK_EQUAL( numOfSolutions, 2 );
	BOOST_CHECK_EQUAL( roots[0], -1 );
	BOOST_CHECK_EQUAL( roots[1], 3);
	
	// D==0
	try
	{
		numOfSolutions = mathTools.solveQuadratic(1,0,0, roots);
	} catch (std::exception& e) {
		BOOST_FAIL( e.what() );
	}
	BOOST_CHECK_EQUAL( numOfSolutions, 1 );
	BOOST_CHECK_EQUAL( roots[0], 0 );
	BOOST_CHECK_EQUAL( roots[1], 0 );
	
	// D<0
	try
	{
		numOfSolutions = mathTools.solveQuadratic(1,1,10, roots);
		BOOST_FAIL( "solveQuadratic should be D<0 so no solutions!" );
	} catch (std::exception& e) {} 
}
