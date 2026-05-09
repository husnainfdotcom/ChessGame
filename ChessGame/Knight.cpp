#include"Knight.h"
#include<cmath>

Knight::Knight(char c) :Piece(c, 'K') {};
bool Knight::isValidMove(int startX,int startY,int endX,int endY) {
	int xdiff = abs(startX - endX);
	int ydiff = abs(startY - endY);
	if (xdiff == 2 && ydiff == 1) {
		return true;
	}if (xdiff == 1 && ydiff == 2) {
		return true;
	}return false;
}