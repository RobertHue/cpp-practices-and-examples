//Filename: MazeReader.h
//Description: Declarations for MazeReader class
//Assignment: EECS 268 Lab 10
//Author: Henry C. Nguyen
//Email: h724n828@ku.edu
//Date: 5-7-2014
//

#ifndef MAZEREADER_H
#define MAZEREADER_H

#include <fstream>
#include <iostream>
#include <string>
#include "MazeCreationException.h"

class MazeReader
{
public:

	MazeReader(std::string file) throw (MazeCreationException);

	~MazeReader();

	char** getMaze() const;

	int getCols() const;

	int getRows() const;

	int getStartCol() const;

	int getStartRow() const;

private:
	char** m_maze;

	int m_rows;

	int m_columns;
	
	int m_start_x;
	
	int m_start_y;
protected:
	void readMaze() throw (MazeCreationException);
};

#endif
