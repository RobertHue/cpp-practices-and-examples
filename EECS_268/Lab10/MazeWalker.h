//Filename: MazeWalker.h
//Description: Declaration of MazeWalker class
//Assignment: EECS 268 Lab 10
//Author: Henry C. Nguyen
//Email: h724n828@ku.edu
//Date: 5-8-2014
//
#ifndef MAZEWALKER_H
#define MAZEWALKER_H

#include <iostream>
#include <stack>
#include <queue>
#include "Position.h"

class MazeWalker
{
public:
	MazeWalker(char** mazePtr, int startRow, int startCol, int rows, int cols, bool dfs);

	void walkMaze();

protected:
	void storeValidMoves();

	void move(Position& p);

	bool isGoalReached() const;

	//member variables
	bool m_isDFS;

	char** m_maze;

	bool** m_visited;

	int m_rows, m_cols;

	Position m_curPos;

	Position m_startPos;

	std::stack<Position> m_moveStack;
	std::queue<Position> m_moveQueue;
};

#endif
