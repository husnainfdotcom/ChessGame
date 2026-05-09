#include <iostream>
#include "Board.h"
using namespace std;

int main()
{
	Board gameBoard;
	bool isWhiteTurn = true;
	bool gameOver = false;
	int startX, startY, endX, endY;

	cout << "--- Chess Game Engine Initialized ---" << endl;

	while (!gameOver)
	{
		gameBoard.displayBoard();

		if (isWhiteTurn)
		{
			cout << "\nWhite turn: ";
		}
		else
		{
			cout << "\nBlack turn: ";
		}

		cin >> startX >> startY >> endX >> endY;

		bool success = gameBoard.movePiece(startX, startY, endX, endY, isWhiteTurn);

		if (success)
		{
			isWhiteTurn = !isWhiteTurn;
		}
	}

	return 0;
}