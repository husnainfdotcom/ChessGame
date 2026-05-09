#ifndef PIECE_H
#define PIECE_H

class Piece {
protected:
    char color;
    char symbol;
public:
    Piece(char c, char s) {
        color = c;
        symbol = s;
    }
    virtual ~Piece() {}

    // Pure virtual function: This forces you to write this function in every child class.
    virtual bool isValidMove(int startX, int startY, int endX, int endY) = 0;
};

#endif
