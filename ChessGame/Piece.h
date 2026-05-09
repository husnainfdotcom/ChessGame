#pragma once

class Piece
{
protected:
	bool isWhite;
	char symbol;
public:
	Piece(bool white, char sym)
	{
		isWhite = white;
		symbol = sym;
	}
	virtual ~Piece()
	{}
	bool getIsWhite()
	{
		return isWhite;
	}
	char getSymbol()
	{
		return symbol;
	}
	virtual bool isValidMove(int startX, int startY, int endX, int endY, Piece* board[8][8]) = 0;
};