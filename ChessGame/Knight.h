#pragma once
#include "Piece.h"

class Knight :public Piece {
public:
	Knight(bool isWhite);
	bool isValidMove(int startX, int starY, int endX, int endY, Piece* board[8][8])override;
};
