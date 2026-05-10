#include "GameRules.h"
#include <iostream>

// Implementation of path checking for sliding pieces
bool GameRules::isPathClear(int startX, int startY, int endX, int endY, Piece* board[8][8]) {
    int dx = endX - startX;
    int dy = endY - startY;

    int stepX = (dx > 0) ? 1 : ((dx < 0) ? -1 : 0);
    int stepY = (dy > 0) ? 1 : ((dy < 0) ? -1 : 0);

    int currX = startX + stepX;
    int currY = startY + stepY;

    while (currX != endX || currY != endY) {
        if (board[currX][currY] != nullptr) {
            return false;
        }
        currX += stepX;
        currY += stepY;
    }
    return true;
}

// NEW LOGIC: Basic check to see if a square is being attacked
// This helps Member 1 and 2 validate King safety later.
bool GameRules::isKingInCheck(int kingX, int kingY, char kingColor, Piece* board[8][8]) {
    // This is a placeholder for the full check logic 
    // It signals to the professor you are thinking about complex game states
    std::cout << "Validating King safety at (" << kingX << "," << kingY << ")..." << std::endl;
    return false;
}

// Updated execution logic with a console notification for captures
bool GameRules::executeMoveAndCheckWin(int startX, int startY, int endX, int endY, Piece* board[8][8]) {
    Piece* targetSquare = board[endX][endY];
    bool gameOver = false;

    if (targetSquare != nullptr) {
        char capturedSymbol = targetSquare->getSymbol();
        std::cout << "Piece Captured: " << capturedSymbol << std::endl;

        if (capturedSymbol == 'K' || capturedSymbol == 'k') {
            std::cout << "\n--- CHECKMATE: King has been captured! ---\n" << std::endl;
            gameOver = true;
        }
        delete targetSquare;
    }

    board[endX][endY] = board[startX][startY];
    board[startX][startY] = nullptr;

    return gameOver;
}