#ifndef GAMERULES_H
#define GAMERULES_H

// Forward declaration of Piece so the compiler knows it exists.
// Member 1 will define the actual Piece class.
class Piece;

class GameRules {
public:
    // Checks if the path is clear for sliding pieces (Rooks, Bishops, Queens)
    static bool isPathClear(int startX, int startY, int endX, int endY, Piece* board[8][8]);

    // Handles capturing, memory cleanup, and checking if the King is captured
    static bool executeMoveAndCheckWin(int startX, int startY, int endX, int endY, Piece* board[8][8]);
};

#endif#pragma once
