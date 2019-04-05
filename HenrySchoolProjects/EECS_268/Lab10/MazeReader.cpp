//Filename: MazeReader.h
//Description: MazeReader class definitions
//Assignment: EECS 268 Lab 10
//Author: Henry C. Nguyen
//Email: h724n828@ku.edu
//Date: 5-8-2014
//

#include "MazeReader.h"

MazeReader::MazeReader(std::string file) throw(MazeCreationException)
{
	m_rows = 0;
	m_columns = 0;
	std::ifstream infile;
	infile.open(file);

	if(infile.is_open())
	{
		std::cout << "File successfully opened." << std::endl << "--File information--" << std::endl;

		//read dimensions of the file on the first line
		//read start position of the file on the second line
		std::string temp;
		for(int i = 0; i < 2; ++i)
		{
			if(std::getline(infile, temp))
			{
				for(int j = 0; j < temp.size(); ++j)
				{
					if(i == 0 && j == 0)
					{
						m_rows = temp.at(j) - 48;
						std::cout << "Rows [" << m_rows << "]" << std::endl;			
					}
					if(i == 0 && j == 2)
					{
						m_columns = temp.at(j) - 48;
						std::cout << "Columns [" << m_columns << "]" << std::endl;
					}
					if(i == 1 && j == 0)
					{
						m_start_x = temp.at(j) - 48;
						std::cout << "Start X <" << m_start_x << ">" << std::endl;
					}	
					if(i == 1 && j == 2)
					{
						m_start_y = temp.at(j) - 48;
						std::cout << "Start Y <" << m_start_y << ">" << std::endl;
					}
				}
			}
		}

		std::cout << "--Output--" << std::endl;

		//copy file to array member
		m_maze = new char*[m_rows];	//allocate rows
		for(int i = 2 ; i <= (2+m_rows); ++i)
		{
			//allocate line of columns
			m_maze[i-2] = new char[m_columns];
			for(int j = 0; j < m_columns; ++j)
			{
				m_maze[i-2][j] = infile.get();
				if(m_maze[i-2][j] == 's')
				{
					m_start_y = i;
					m_start_x = j;
				}
				std::cout << m_maze[i-2][j];
			}
		}
	}
	else
	{
		throw("File could not be opened");
	}
}

MazeReader::~MazeReader()
{
	for(int i = 0; i < m_rows; ++i)
	{
		delete[] m_maze[i];
	}
	delete[] m_maze;
}

char** MazeReader::getMaze() const
{
	return m_maze;
}

int MazeReader::getCols() const
{
	return m_columns;
}

int MazeReader::getRows() const
{
	return m_rows;
}

int MazeReader::getStartCol() const
{
	return m_start_x;	
}

int MazeReader::getStartRow() const
{
	return m_start_y;
}
