#include "GameRules.h"
#include "Piece.h" // Required so the compiler knows what a Piece is
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
        // FIXED: Swapped to [currY][currX] to match 2D array memory logic
        if (board[currY][currX] != nullptr) {
            return false;
        }
        currX += stepX;
        currY += stepY;
    }
    return true;
}

// NEW LOGIC: Basic check to see if a square is being attacked
// This helps Member 1 and 2 validate King safety later.
bool GameRules::isKingInCheck(int kingX, int kingY, bool isWhiteKing, Piece* board[8][8]) {
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            if (board[y][x] != nullptr && board[y][x]->getIsWhite() != isWhiteKing) {
                if (board[y][x]->isValidMove(x, y, kingX, kingY, board)) {
                    char sym = board[y][x]->getSymbol();
                    if (sym == 'N' || sym == 'n' || isPathClear(x, y, kingX, kingY, board)) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

// NEW LOGIC: Simulates every possible move to see if Checkmate is true
bool GameRules::isCheckmate(bool isWhiteKing, Piece* board[8][8]) {
    int kingX = -1, kingY = -1;

    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            if (board[y][x] != nullptr && board[y][x]->getIsWhite() == isWhiteKing) {
                char sym = board[y][x]->getSymbol();
                if (sym == 'K' || sym == 'k') {
                    kingX = x; kingY = y;
                }
            }
        }
    }

    if (!isKingInCheck(kingX, kingY, isWhiteKing, board)) {
        return false;
    }

    for (int startY = 0; startY < 8; startY++) {
        for (int startX = 0; startX < 8; startX++) {
            if (board[startY][startX] != nullptr && board[startY][startX]->getIsWhite() == isWhiteKing) {
                for (int endY = 0; endY < 8; endY++) {
                    for (int endX = 0; endX < 8; endX++) {

                        if (board[endY][endX] != nullptr && board[endY][endX]->getIsWhite() == isWhiteKing) continue;

                        if (board[startY][startX]->isValidMove(startX, startY, endX, endY, board)) {
                            char sym = board[startY][startX]->getSymbol();
                            if (sym == 'N' || sym == 'n' || isPathClear(startX, startY, endX, endY, board)) {

                                Piece* tempTarget = board[endY][endX];
                                board[endY][endX] = board[startY][startX];
                                board[startY][startX] = nullptr;

                                int newKingX = (sym == 'K' || sym == 'k') ? endX : kingX;
                                int newKingY = (sym == 'K' || sym == 'k') ? endY : kingY;

                                bool stillInCheck = isKingInCheck(newKingX, newKingY, isWhiteKing, board);

                                board[startY][startX] = board[endY][endX];
                                board[endY][endX] = tempTarget;

                                if (!stillInCheck) {
                                    return false;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return true;
}

// Updated execution logic with a console notification for captures
bool GameRules::executeMoveAndCheckWin(int startX, int startY, int endX, int endY, Piece* board[8][8]) {
    // FIXED: Swapped X and Y for the 2D array target square
    Piece* targetSquare = board[endY][endX];
    bool isWhiteTurn = board[startY][startX]->getIsWhite();
    bool gameOver = false;

    if (targetSquare != nullptr) {
        char capturedSymbol = targetSquare->getSymbol();
        std::cout << "Piece Captured: " << capturedSymbol << std::endl;
        delete targetSquare;
    }

    // FIXED: Swapped X and Y for the move execution
    board[endY][endX] = board[startY][startX];
    board[startY][startX] = nullptr;

    bool opponentIsWhite = !isWhiteTurn;
    if (isCheckmate(opponentIsWhite, board)) {
        std::cout << "\n--- TRUE CHECKMATE: No legal moves left! ---\n" << std::endl;
        gameOver = true;
    }

    return gameOver;
}