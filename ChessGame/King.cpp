#include "King.h"
#include <cmath>
using namespace std;

King::King(bool isWhite) : Piece(isWhite, 'K')
{
}

bool King::isValidMove(int startX, int startY, int endX, int endY, Piece* board[8][8])
{
	if (startX == endX && startY == endY)
	{
		return false;
	}

	int xdiff = abs(startX - endX);
	int ydiff = abs(startY - endY);

	if (xdiff <= 1 && ydiff <= 1)
	{
		return true;
	}
	return false;
}