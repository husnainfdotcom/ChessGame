#include "Pawn.h"
#include <cmath>

Pawn::Pawn(char c) :Piece (c, 'P') {};

bool Pawn::isValidMove(int startX,int startY,int endX,int endY) {
	if (startX == endX&&startY==endY) {
		return false;
	}
	int direction = (color == 'W') ?- 1:1;
	int startingRow = (color == 'W') ? 6 : 1;
	if (startY == endY && endX == startX + direction) {
		return true;
	}
	if (startY == endY && startX == startingRow && endX == startX + (2 * direction)) {//first turn logic
		return true;
	}
	if (endX == startX && abs(startY - endY) == 1) {//killing logic
		return true;
	}
	return false;
}
