#include"Knight.h"
#include<cmath>

Knight::Knight(bool isWhite) :Piece(isWhite, 'N') {};
bool Knight::isValidMove(int startX, int startY, int endX, int endY, Piece* board[8][8]) {
	int xdiff = abs(startX - endX);
	int ydiff = abs(startY - endY);
	if (xdiff == 2 && ydiff == 1) {
		return true;
	}if (xdiff == 1 && ydiff == 2) {
		return true;
	}return false;
}