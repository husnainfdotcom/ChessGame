#include <iostream>
#include "Board.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Pawn.h"
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
	//Black Pieces (false)	
	grid[0][0] = new Rook(false);
	grid[0][1] = new Knight(false);
	grid[0][2] = new Bishop(false);
	grid[0][3] = new Queen(false);
	grid[0][4] = new King(false);
	grid[0][5] = new Bishop(false);
	grid[0][6] = new Knight(false);
	grid[0][7] = new Rook(false);

	for (int i = 0; i < 8; i++)
	{
		grid[1][i] = new Pawn(false);
	}
	
	//White Pieces (true)
	for (int i = 0; i < 8; i++)
	{
		grid[6][i] = new Pawn(true);
	}

	grid[7][0] = new Rook(true);
	grid[7][1] = new Knight(true);
	grid[7][2] = new Bishop(true);
	grid[7][3] = new Queen(true);
	grid[7][4] = new King(true);
	grid[7][5] = new Bishop(true);
	grid[7][6] = new Knight(true);
	grid[7][7] = new Rook(true);
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

	// Ask Member 2 if the math/geometry is valid
	if (grid[startY][startX]->isValidMove(startX, startY, endX, endY, grid))
	{
		// Basic capture before Member 3's advanced logic
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
