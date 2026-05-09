#include "Rook.h"

// Constructor: Parent (Piece) ko user ka diya hua color pass karein aur symbol 'R' fix kar dein
Rook::Rook(char c) : Piece(c, 'R') {}

bool Rook::isValidMove(int startX, int startY, int endX, int endY) {

    // Safety Check: Agar start aur end point bilkul same hain, 
    // iska matlab piece hila hi nahi. Toh ye ghalat move hai.
    if (startX == endX && startY == endY) {
        return false;
    }

    // Rook (Haathi) sirf seedha chalta hai: 
    // Ya toh row (X) same rahegi (vertical move) ya column (Y) same rahega (horizontal move)
    if (startX == endX || startY == endY) {
        return true; // Move math ke hisaab se sahi hai
    }

    return false; // Agar move seedha nahi tha, toh false return karo
}