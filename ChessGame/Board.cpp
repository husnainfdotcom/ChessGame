#include <iostream>
#include "Board.h"
using namespace std;

//initialize empty board
Board::Board()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			grid[i][j] = nullptr;
		}
	}
}

//cleanup memory
Board::~Board()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (grid[i][j] != nullptr)
			{
				delete grid[i][j];
			}
		}
	}
}

//print board
void Board::displayBoard()
{
	cout << "  0 1 2 3 4 5 6 7" << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << i << " ";
		for (int j = 0; j < 8; j++)
		{
			if (grid[i][j] == nullptr)
			{
				cout << ". ";
			}
			else
			{
				cout << grid[i][j]->getSymbol() << " ";
			}
		}
		cout << endl;
	}
}

//basic move logic before member 3 integration
bool Board::movePiece(int startX, int startY, int endX, int endY, bool isWhiteTurn)
{
	if (grid[startY][startX] == nullptr)
	{
		cout << "no piece there" << endl;
		return false;
	}
	if (grid[startY][startX]->getIsWhite() != isWhiteTurn)
	{
		cout << "not your turn" << endl;
		return false;
	}
	if (grid[startY][startX]->isValidMove(startX, startY, endX, endY, grid))
	{
		if (grid[endY][endX] != nullptr)
		{
			delete grid[endY][endX];
		}
		grid[endY][endX] = grid[startY][startX];
		grid[startY][startX] = nullptr;
		return true;
	}
	cout << "invalid move" << endl;
	return false;
}