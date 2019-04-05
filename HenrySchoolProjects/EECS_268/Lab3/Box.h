//Filename: Box.h
//Author: Henry C. Nguyen
//Assignment: EECS 268 Lab 3
//Description: File is the header file for the Box class and contains necessary prototypes for class methods and members.
//Date: 2-27-14
//Email: h724n828@ku.edu
//
#ifndef BOX_H
#define BOX_H

class Box {
	public:
		
		//Default Constructor which initializes all member variables
		//@pre None
		//@post Creates and initializes Box instance
		//@return Initialized Box with 0 value and nullptr as m_previous
		Box();

		//Alternative Constructor for value and previous address input
		//@pre value is an integer and previous must be an address for Box
		//@post Creates and initializes Box instance with desired value and previous address
		//@return Initialized Box with desired member variables
		Box(int value, Box* previous);

		//Alternative Constructor for only value input
		//@pre value is an integer
		//@post Creates and initializes Box instance with desired value
		//@return Initialized Box with desired value and nullptr as previous address
		Box(int value);
		
		//Set methods for member variables
		//@pre value is an integer
		//@post sets member variable m_value to desired 
		void setValue(int value);

		//@pre parameter is a pointer for Box
		//@post sets member pointer to input address
		void setPrevious(Box* previous);

		//Get methods for member variables


		//@pre none
		//@post returns integer
		//@return stored value in Box
		int getValue();

		//@pre None
		//@post returns a pointer for Box
		//@return returns address of previous box
		Box* getPrevious();

	private:
		//Member variables
		//Stores an integer value to represent the box
		int m_value;
		//Stores the address in which the box exists
		Box* m_previous;
};

#endif
