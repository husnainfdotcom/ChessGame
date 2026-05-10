#include "Pawn.h"
#include <cmath>

Pawn::Pawn(bool isWhite) :Piece(isWhite, 'P') {};

bool Pawn::isValidMove(int startX, int startY, int endX, int endY, Piece* board[8][8]) {
	if (startX == endX && startY == endY) {
		return false;
	}
	int direction = (isWhite) ? -1 : 1;
	int startingRow = (isWhite) ? 6 : 1;
	if (startX == endX && endY == startY + direction) {
		return true;
	}
	if (startX == endX && startY == startingRow && endY == startY + (2 * direction)) {//first turn logic
		return true;
	}
	if (abs(startX - endX) == 1 && endY == startY + direction) {//killing logic
		return true;
	}
	return false;
}