#include "Queen.h"
#include<cmath>

Queen::Queen(char c) :Piece(c, 'Q') {};

bool Queen::isValidMove(int startX, int startY, int endX, int endY) {
	int xdiff = abs(startX - endX);
	int ydiff = abs(startY - endY);
	if (startX == endX && startY == endY) {
		return false;
	}
	bool isStraight = (startX == endX || startY == endY);
	bool isDiagonal = (xdiff == ydiff);
	if (isStraight || isDiagonal) {
		return true;
	}
	return false;
}
