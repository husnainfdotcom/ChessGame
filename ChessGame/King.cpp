#include"King.h"
#include<cmath>

King::King(char c) :Piece(c, 'K') {};

bool King::isValidMove(int startX, int startY, int endX, int endY) {
	if (startX == endX && startY == endY) {
		return false;
	}
	int xdiff = abs(startX - endX);
	int ydiff = abs(startY - endY);
	if (xdiff <= 1 &&ydiff <= 1) {
		return true;
	}
	return false;
}