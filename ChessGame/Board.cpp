#include <iostream>
#include "Board.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Pawn.h"
#include "GameRules.h" // Added Member 3's rules

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

//final move logic with member 3 integration
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
		// Ask Member 3 if the path is blocked (Knights 'N' are allowed to jump over pieces)
		char pieceSymbol = grid[startY][startX]->getSymbol();
		if (pieceSymbol != 'N' && pieceSymbol != 'n')
		{
			if (!GameRules::isPathClear(startX, startY, endX, endY, grid))
			{
				cout << "path is blocked by another piece" << endl;
				return false;
			}
		}

		// --- NEW: Escape Ludo Logic (Validate King Safety) ---
		// We temporarily simulate the move to see if it leaves our King in check
		Piece* tempTarget = grid[endY][endX];
		grid[endY][endX] = grid[startY][startX];
		grid[startY][startX] = nullptr;

		// Find current King position to check safety
		int kX = -1, kY = -1;
		for (int y = 0; y < 8; y++) {
			for (int x = 0; x < 8; x++) {
				if (grid[y][x] != nullptr && grid[y][x]->getIsWhite() == isWhiteTurn) {
					char s = grid[y][x]->getSymbol();
					if (s == 'K' || s == 'k') { kX = x; kY = y; }
				}
			}
		}

		bool safetyCheck = GameRules::isKingInCheck(kX, kY, isWhiteTurn, grid);

		// Undo simulation
		grid[startY][startX] = grid[endY][endX];
		grid[endY][endX] = tempTarget;

		if (safetyCheck) {
			cout << "Invalid move: You cannot leave your King in Check!" << endl;
			return false;
		}
		// --- End of Safety Validation ---

		// Ask Member 3 to execute the move and check if a True Checkmate occurred
		bool isCheckmate = GameRules::executeMoveAndCheckWin(startX, startY, endX, endY, grid);

		if (isCheckmate)
		{
			displayBoard(); // Show final board state
			exit(0);
		}

		return true;
	}

	cout << "invalid move" << endl;
	return false;
}