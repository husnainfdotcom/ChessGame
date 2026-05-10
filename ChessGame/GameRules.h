#ifndef GAMERULES_H
#define GAMERULES_H

// Forward declaration of Piece so the compiler knows it exists.
// Member 1 will define the actual Piece class.
class Piece;

class GameRules {
public:
    // Checks if the path is clear for sliding pieces (Rooks, Bishops, Queens)
    static bool isPathClear(int startX, int startY, int endX, int endY, Piece* board[8][8]);

    // NEW LOGIC: Basic check to see if a square is being attacked
    // This helps Member 1 and 2 validate King safety later.
    static bool isKingInCheck(int kingX, int kingY, bool isWhiteKing, Piece* board[8][8]);

    // NEW LOGIC: Simulates every possible move to see if Checkmate is true
    static bool isCheckmate(bool isWhiteKing, Piece* board[8][8]);

    // Handles capturing, memory cleanup, and checking if the King is captured
    static bool executeMoveAndCheckWin(int startX, int startY, int endX, int endY, Piece* board[8][8]);
};

#endif
#pragma once