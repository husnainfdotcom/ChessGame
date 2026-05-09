#pragma once
#include "Piece.h"

class King :public Piece {
public:
	King(char c);
	bool isValidMove(int startX, int startY, int endX, int endY)override;
};
