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

	// Expose piece info for GUI drawing without breaking encapsulation
	Piece* getPiece(int x, int y) {
		if (x >= 0 && x < 8 && y >= 0 && y < 8) {
			return grid[y][x];
		}
		return nullptr;
	}
};