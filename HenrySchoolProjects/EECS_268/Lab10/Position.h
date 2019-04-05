//Filename: Position.h
//Description: Definitions for position class container
//Assignment: EECS 268 Lab 10
//Author: Henry C. Nguyen
//Email: h724n828@ku.edu
//Date: 5-07-2014

#ifndef POSITION_H
#define POSITION_H

class Position
{
public:
	//@pre parameters are valid
	//@post assigns row and col to member variables
	//@return none
	Position(int row, int col);

	//@pre member variables are initialized
	//@post none
	//@return m_row value
	int getRow() const;

	//@pre member variables are initialized
	//@post none
	//@return m_col value
	int getCol() const;

private:
	int m_row;
	
	int m_col;
};

#endif
