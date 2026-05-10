#include "GameRules.h"
#include <iostream>
#include <cmath>

// TEMPORARY: Minimal definition of Piece so your code compiles locally.
// Replace this with: #include "Piece.h" once Member 1 pushes their code.
class Piece {
public:
    virtual char getSymbol() = 0;
    virtual ~Piece() {}
};

// Implementation of path checking
bool GameRules::isPathClear(int startX, int startY, int endX, int endY, Piece* board[8][8]) {
    int dx = endX - startX;
    int dy = endY - startY;

    // Determine the step direction (-1, 0, or 1)
    int stepX = (dx > 0) ? 1 : ((dx < 0) ? -1 : 0);
    int stepY = (dy > 0) ? 1 : ((dy < 0) ? -1 : 0);

    int currX = startX + stepX;
    int currY = startY + stepY;

    // Traverse the path until we reach the destination square
    while (currX != endX || currY != endY) {
        if (board[currX][currY] != nullptr) {
            return false; // Path is blocked by another piece
        }
        currX += stepX;
        currY += stepY;
    }
    return true;
}

// Implementation of capture logic and win condition
bool GameRules::executeMoveAndCheckWin(int startX, int startY, int endX, int endY, Piece* board[8][8]) {
    Piece* targetSquare = board[endX][endY];
    bool gameOver = false;

    if (targetSquare != nullptr) {
        char capturedSymbol = targetSquare->getSymbol();

        // Detect if the captured piece is a King
        if (capturedSymbol == 'K' || capturedSymbol == 'k') {
            std::cout << "\nKing captured! Checkmate. Game Over.\n" << std::endl;
            gameOver = true;
        }

        // Free the memory of the captured piece to prevent memory leaks
        delete targetSquare;
    }

    // Move the piece pointer to the new square
    board[endX][endY] = board[startX][startY];
    board[startX][startY] = nullptr; // Clear the old square pointer

    return gameOver;
}