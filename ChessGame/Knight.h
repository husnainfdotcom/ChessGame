#pragma once
#include "Piece.h"

class Knight:public Piece{
public:
	Knight(char c);
	bool isValidMove(int startX, int starY, int endX, int endY)override;
};
