#pragma once
#include "Piece.h"

class Pawn :public Piece {
public:
	Pawn(char c);
	bool isValidMove(int startX, int startY, int endX, int endY)override; 
};
