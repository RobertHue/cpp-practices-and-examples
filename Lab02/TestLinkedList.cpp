 /**
*	@file TestLinkedList.cpp
*	@author Robert Hümmer
*	@date 18.12.2016
*	@brief A test suite which checks the correct functioning of the LinkedList implementation
*/
#define BOOST_TEST_DYN_LINK	// boost generates a main for you if you use this define
#define BOOST_TEST_MODULE TEST_MODULE_LL	// must be defined before unit_test.hpp
#include <boost/test/unit_test.hpp>	// link with the precompiled test library with this header file
#include "LinkedList.h"
#include "MedicalExecutive.h"
#include <iostream>
using namespace std;

BOOST_AUTO_TEST_SUITE( test_linked_list )


BOOST_AUTO_TEST_CASE( test_emptyList )
{
	LinkedList<int> ll;
	
	BOOST_CHECK(ll.isEmpty() == true);
}


BOOST_AUTO_TEST_CASE( test_listWithOneElement ) 
{
	LinkedList<int> ll;
	ll.addFront(42);
	
	BOOST_CHECK(ll.getEntry(1) == 42);
	BOOST_CHECK(ll.getLength() == 1);
}


BOOST_AUTO_TEST_CASE( test_listWithFiveElements )
{
	LinkedList<int> ll; 
	ll.addFront(42);
	ll.addBack(22);
	ll.addBack(33);
	ll.addFront(77);
	ll.insert(3, 9000);
	
	BOOST_CHECK(ll.getEntry(1) == 77);
	BOOST_CHECK(ll.getEntry(2) == 42);
	BOOST_CHECK(ll.getEntry(3) == 9000);
	BOOST_CHECK(ll.getEntry(4) == 22);
	BOOST_CHECK(ll.getEntry(5) == 33);
	
	BOOST_CHECK(ll.getLength() == 5);
}

BOOST_AUTO_TEST_CASE( test_insertInOrderIntoLL )
{
	LinkedList<int> ll;
	vector<int> vec;	// Elements as user-input or textfile
	vec.push_back(42);
	vec.push_back(22);
	vec.push_back(33);
	vec.push_back(77);
	vec.push_back(9000);
	
	// insertInOrderLLAlgorithm here:
	ll.addFront( vec[0] );
	for(unsigned int j=1; j<vec.size(); ++j)
	{
		MedicalExecutive::insertInOrderIntoLL<int>(ll, vec[j], vec[j]);
		
	}
	BOOST_CHECK(ll.getLength() == 5);
	
	// Expection: descending ordering 
	BOOST_CHECK(ll.getEntry(1) == 9000);
	BOOST_CHECK(ll.getEntry(2) == 77);
	BOOST_CHECK(ll.getEntry(3) == 42);
	BOOST_CHECK(ll.getEntry(4) == 33);
	BOOST_CHECK(ll.getEntry(5) == 22);
}

BOOST_AUTO_TEST_CASE( test_removeFrontLL )
{
	bool worked;
	LinkedList<int> ll;
	ll.addBack(42);
	ll.addBack(77);
	ll.addBack(133);
	ll.addBack(255);
	
	BOOST_CHECK(ll.getLength() == 4);
	BOOST_CHECK(ll.getEntry(1) == 42);
	BOOST_CHECK(ll.getEntry(2) == 77); 
	BOOST_CHECK(ll.getEntry(3) == 133);
	BOOST_CHECK(ll.getEntry(4) == 255);
	
	worked = ll.removeFront();
	BOOST_CHECK(worked == true);
	BOOST_CHECK(ll.getLength() == 3); 
	BOOST_CHECK(ll.getEntry(1) == 77);
	BOOST_CHECK(ll.getEntry(2) == 133);
	BOOST_CHECK(ll.getEntry(3) == 255);
	
	worked = ll.removeFront();
	BOOST_CHECK(worked == true);
	BOOST_CHECK(ll.getLength() == 2); 
	BOOST_CHECK(ll.getEntry(1) == 133);
	BOOST_CHECK(ll.getEntry(2) == 255);
	
	worked = ll.removeFront();
	BOOST_CHECK(worked == true);
	BOOST_CHECK(ll.getLength() == 1);
	BOOST_CHECK(ll.getEntry(1) == 255);
	
	worked = ll.removeFront();
	BOOST_CHECK(worked == true);
	BOOST_CHECK(ll.getLength() == 0);
	BOOST_CHECK(ll.isEmpty() == true); 
	
}
BOOST_AUTO_TEST_CASE( test_removeAtLL )
{
	bool worked;
	LinkedList<int> ll;
	ll.addBack(42);
	ll.addBack(77);
	ll.addBack(133);
	ll.addBack(255);
	
	BOOST_CHECK(ll.getLength() == 4);
	BOOST_CHECK(ll.getEntry(1) == 42);
	BOOST_CHECK(ll.getEntry(2) == 77); 
	BOOST_CHECK(ll.getEntry(3) == 133);
	BOOST_CHECK(ll.getEntry(4) == 255);
		
	worked = ll.removeAt(3);
	BOOST_CHECK(worked == true);
	BOOST_CHECK(ll.getLength() == 3);
	BOOST_CHECK(ll.getEntry(1) == 42);
	BOOST_CHECK(ll.getEntry(2) == 77);
	BOOST_CHECK(ll.getEntry(3) == 255);
	
	worked = ll.removeAt(3);
	BOOST_CHECK(worked == true);
	BOOST_CHECK(ll.getLength() == 2);
	BOOST_CHECK(ll.getEntry(1) == 42);
	BOOST_CHECK(ll.getEntry(2) == 77);
	
	worked = ll.removeAt(1);
	BOOST_CHECK(worked == true);
	BOOST_CHECK(ll.getLength() == 1);
	BOOST_CHECK(ll.getEntry(1) == 77);
	
	worked = ll.removeAt(1);
	BOOST_CHECK(worked == true);
	BOOST_CHECK(ll.getLength() == 0);
	BOOST_CHECK(ll.isEmpty() == true);	
}

BOOST_AUTO_TEST_CASE( test_removeBackLL )
{
	bool worked;
	LinkedList<int> ll;
	ll.addBack(42);
	ll.addBack(77);
	ll.addBack(133);
	ll.addBack(255);
	
	BOOST_CHECK(ll.getLength() == 4);
	BOOST_CHECK(ll.getEntry(1) == 42);
	BOOST_CHECK(ll.getEntry(2) == 77); 
	BOOST_CHECK(ll.getEntry(3) == 133);
	BOOST_CHECK(ll.getEntry(4) == 255);
		
	worked = ll.removeBack();
	BOOST_CHECK(worked == true);
	BOOST_CHECK(ll.getLength() == 3);
	BOOST_CHECK(ll.getEntry(1) == 42);
	BOOST_CHECK(ll.getEntry(2) == 77); 
	BOOST_CHECK(ll.getEntry(3) == 133);
	
	worked = ll.removeBack();
	BOOST_CHECK(worked == true);
	BOOST_CHECK(ll.getLength() == 2);
	BOOST_CHECK(ll.getEntry(1) == 42);
	BOOST_CHECK(ll.getEntry(2) == 77); 
	
	worked = ll.removeBack();
	BOOST_CHECK(worked == true);
	BOOST_CHECK(ll.getLength() == 1);
	BOOST_CHECK(ll.getEntry(1) == 42);
	
	worked = ll.removeBack();
	BOOST_CHECK(worked == true);
	BOOST_CHECK(ll.getLength() == 0);
	BOOST_CHECK(ll.isEmpty() == true);	
}

BOOST_AUTO_TEST_CASE( test_positionOfLL )
{
	int position;
	LinkedList<int> ll;
	ll.addBack(42);
	ll.addBack(77);
	ll.addBack(133);
	ll.addBack(255);
	
	BOOST_CHECK(ll.getLength() == 4);
	BOOST_CHECK(ll.getEntry(1) == 42);
	BOOST_CHECK(ll.getEntry(2) == 77); 
	BOOST_CHECK(ll.getEntry(3) == 133);
	BOOST_CHECK(ll.getEntry(4) == 255);
		
	position = ll.positionOf(133);
	BOOST_CHECK( position == 3 );
	
	position = ll.positionOf(255);
	BOOST_CHECK( position == 4 );
	
	position = ll.positionOf(42);
	BOOST_CHECK( position == 1 );
}

BOOST_AUTO_TEST_CASE( test_insertLL )
{
	LinkedList<int> ll;
	
	BOOST_CHECK(ll.getLength() == 0);
	
	ll.insert(1,42);	// 42
	
	BOOST_CHECK(ll.getLength() == 1);
	BOOST_CHECK(ll.getEntry(1) == 42); 
	
	ll.insert(2,77);	// 42 77
	
	BOOST_CHECK(ll.getLength() == 2);
	BOOST_CHECK(ll.getEntry(1) == 42); 
	BOOST_CHECK(ll.getEntry(2) == 77);
	
	ll.insert(1,133);	// 133 42 77
	
	BOOST_CHECK(ll.getLength() == 3);
	BOOST_CHECK(ll.getEntry(1) == 133);
	BOOST_CHECK(ll.getEntry(2) == 42); 
	BOOST_CHECK(ll.getEntry(3) == 77);
	
	ll.insert(2,255);	// 133 255 42 77
	
	BOOST_CHECK(ll.getLength() == 4);
	BOOST_CHECK(ll.getEntry(1) == 133);
	BOOST_CHECK(ll.getEntry(2) == 255); 
	BOOST_CHECK(ll.getEntry(3) == 42);
	BOOST_CHECK(ll.getEntry(4) == 77);
}

BOOST_AUTO_TEST_CASE( test_setEntryLL )
{
	LinkedList<int> ll;
	ll.addBack(42);
	ll.addBack(77);
	ll.addBack(133);
	ll.addBack(255);
	
	BOOST_CHECK(ll.getLength() == 4);
	BOOST_CHECK(ll.getEntry(1) == 42);
	BOOST_CHECK(ll.getEntry(2) == 77); 
	BOOST_CHECK(ll.getEntry(3) == 133);
	BOOST_CHECK(ll.getEntry(4) == 255);
	
	ll.setEntry(2, 144);
	
	BOOST_CHECK(ll.getLength() == 4);
	BOOST_CHECK(ll.getEntry(1) == 42);
	BOOST_CHECK(ll.getEntry(2) == 144); 
	BOOST_CHECK(ll.getEntry(3) == 133);
	BOOST_CHECK(ll.getEntry(4) == 255);
	
	ll.setEntry(3, 7);
	ll.setEntry(4, 6);
	ll.setEntry(1, 5);
	
	BOOST_CHECK(ll.getLength() == 4);
	BOOST_CHECK(ll.getEntry(1) == 5);
	BOOST_CHECK(ll.getEntry(2) == 144); 
	BOOST_CHECK(ll.getEntry(3) == 7);
	BOOST_CHECK(ll.getEntry(4) == 6);
}

BOOST_AUTO_TEST_SUITE_END()
