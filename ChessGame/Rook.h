#pragma once 
#include "Piece.h" 

class Rook : public Piece {
public:
    // Constructor (Color receive karne ke lie)
    Rook(bool isWhite);

    // Movement rule jo hum parent class se override kar rahe hain
    bool isValidMove(int startX, int startY, int endX, int endY, Piece* board[8][8]) override;
};