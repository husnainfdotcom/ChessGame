#pragma once // Naya tareeqa jisse file bar bar copy nahi hoti
#include "Piece.h" // Parent class ko include karna zaroori hai

// Rook class Piece class se properties inherit kar rahi hai
class Rook : public Piece {
public:
    // Constructor (Color receive karne ke lie)
    Rook(char c);

    // Movement rule jo hum parent class se override kar rahe hain
    bool isValidMove(int startX, int startY, int endX, int endY) override;
};