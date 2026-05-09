#pragma once
#include "Piece.h"

class Board
{
	Piece* grid[8][8];
public:
	Board();
	~Board();
	void displayBoard();
	bool movePiece(int startX, int startY, int endX, int endY, bool isWhiteTurn);
};