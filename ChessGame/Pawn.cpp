#include "Pawn.h"
#include <cmath>

Pawn::Pawn(bool isWhite) : Piece(isWhite, 'P') {};

bool Pawn::isValidMove(int startX, int startY, int endX, int endY, Piece* board[8][8]) {
	if (startX == endX && startY == endY) {
		return false;
	}

	int direction = (isWhite) ? -1 : 1;
	int startingRow = (isWhite) ? 6 : 1;

	// 1. Aam Chaal (1 step seedha): Aage wala square bilkul khali (nullptr) hona chahye
	if (startX == endX && endY == startY + direction) {
		if (board[endY][endX] == nullptr) {
			return true;
		}
	}

	// 2. Pehli Chaal (2 steps seedha): Raste wala aur aakhri dono squares khali hone chahye
	if (startX == endX && startY == startingRow && endY == startY + (2 * direction)) {
		if (board[startY + direction][startX] == nullptr && board[endY][endX] == nullptr) {
			return true;
		}
	}

	// 3. Killing Logic (1 step tircha): Wahan lazmi koi dushman piece hona chahye
	if (abs(startX - endX) == 1 && endY == startY + direction) {
		// Check karein ke wahan destination par koi piece mojood hai (khali nahi hai)
		if (board[endY][endX] != nullptr) {

			// Optional but Recommended: Yeh check karna ke wo dushman ka hi piece hai
			// Agar aapke Piece class mein color/isWhite access ho sakta hai toh:
			// if (board[endY][endX]->isWhite != this->isWhite) { return true; }

			return true;
		}
	}

	return false;
}