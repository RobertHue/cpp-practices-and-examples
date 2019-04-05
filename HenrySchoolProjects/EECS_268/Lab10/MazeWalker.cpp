//Filename: MazeWalker.cpp
//Description: MazeWalker definitions
//Assignment: EECS 268 Lab 10
//Author: Henry C. Nguyen
//Email: h724n828@ku.edu
//Date: 5-8-2014
//

#include "MazeWalker.h"

MazeWalker::MazeWalker(char** mazePtr, int startRow, int startCol, int rows, int cols, bool dfs)
{
	m_maze = mazePtr;
	Position newPos(startCol, startRow);
	m_startPos = newPos;
	m_curPos = m_startPos;

	m_visited = new bool*[rows];	
	for(int i = 0; i < rows; ++i)
	{
		m_visited[i] = new bool[cols];
		for(int j = 0; j < cols; ++j)
		{
			m_visited[i][j] = false;
		}
	}
}

MazeWalker::~MazeWalker()
{
	for(int i = 0; i < rows; ++i)
	{
		delete[] m_visted[i];
	}
	delete[] m_visited;
}

void MazeWalker::walkMaze()
{
	while(!isGoalReached())
	{
		for(int i = 0; i < m_rows; ++i)
		{
			for(int j = 0; j < m_cols; ++j)
			{
				if(m_visited[i][j] == true)
				{
					std::cout << "1";
				}
				else
				{
					std::cout << "0";
				}
			}
			std::cout << "\n";
		}			
	}
}

void MazeWalker::storeValidMoves()
{
	if(m_isDFS)
	{
		if(m_maze[m_curPos.getRow() - 1][m_curPos.getCol()] == 'W')
		{
			Position upPos(m_curPos.getRow() -1, m_curPos.getCol());
			m_moveStack.push(upPos);			
		}
		if(m_maze[m_curPos.getRow()][m_curPos.getCol() - 1] == 'W')
		{
			Position leftPos(m_curPos.getRow(), m_curPos.getCol() -1);
			m_moveStack.push(leftPos);
		}
		if(m_maze[m_curPos.getRow() + 1][m_curPos.getCol()] == 'W')
		{
			Position downPos(m_curPos.getRow() + 1, m_curPos.getCol());
			m_moveStack.push(downPos);
		}
		if(m_maze[m_curPos.getRow()][m_curPos.getCol() + 1] == 'W')
		{
			Position rightPos(m_curPos.getRow(), m_curPos.getCol() + 1);
			m_moveStack.push(rightPos);
		}
	}
	else
	{
		if(m_maze[m_curPos.getRow() - 1][m_curPos.getCol()] == 'W')
		{
			Position upPos(m_curPos.getRow() - 1, m_curPos.getCol());
			m_moveQueue.push(upPos);
		}
		if(m_maze[m_curPos.getRow()][m_curPos.getCol()-1] == 'W')
		{
			Position leftPos(m_curPos.getRow(), m_curPos.getCol() - 1);
			m_moveQueue.push(leftPos);
		}
		if(m_maze[m_curPos.getRow() + 1][m_curPos.getCol()] == 'W')
		{
			Position downPos(m_curPos.getRow() + 1, m_curPos.getCol());
			m_moveQueue.push(downPos);
		}
		if(m_maze[m_curPos.getRow()][m_curPos.getCol() + 1] == 'W')
		{
			Position rightPos(m_curPos.getRow(), m_curPos.getCol() + 1);
			m_moveQueue.push(rightPos);
		}
	}
}

void MazeWalker::move(Position& p)
{
	m_curPos = p;
}

bool MazeWalker::isGoalReached() const
{
	if(m_maze[m_curPos.getRow()][m_curPos.getCol()] == 'E')
	{
		return true;	
	}	
	return false;
}
