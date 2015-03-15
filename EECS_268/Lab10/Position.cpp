//Filename: Position.cpp
//Description: Definitions positon class
//Assignment: EECS 268 Lab 10
//Author: Henry C. Nguyen
//Email: h724n828@ku.edu
//Date: 5-8-2014 

#include "Position.h"

Position::Position(int row, int col)
{
	m_row = row;
	m_col = col;
}

int Position::getRow() const
{
	 return m_row;
}

int Position::getCol() const
{
	return m_col;
}
