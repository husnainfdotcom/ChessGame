#include "Bishop.h"
#include <cmath>

Bishop::Bishop(bool isWhite) :Piece(isWhite, 'B') {
}
bool Bishop::isValidMove(int startX, int startY, int endX, int endY, Piece* board[8][8]) {
	int xdiff = abs(startX - endX);
	int ydiff = abs(startY - endY);
	if (xdiff == 0 && ydiff == 0) {
		return false;
	}
	if (xdiff == ydiff) {
		return true;
	}
	else {
		return false;
	}
}