#include <iostream>
#include "Rook.h"
#include "Bishop.h"
#include"Pawn.h"
#include"Queen.h"
#include"King.h"
using namespace std;

int main() {
    Rook myRook('W'); // Create a White Rook

    // Test 1: Moving straight down a column (Valid)
    cout << "Move (0,0) to (0,5): " << myRook.isValidMove(0, 0, 0, 5) << endl;

    // Test 2: Moving straight across a row (Valid)
    cout << "Move (3,3) to (7,3): " << myRook.isValidMove(3, 3, 7, 3) << endl;

    // Test 3: Moving diagonally (Invalid)
    cout << "Move (0,0) to (2,2): " << myRook.isValidMove(0, 0, 2, 2) << endl;

    Bishop myBishop('W');
    cout << "Move (6,1) to (4,3): " << myBishop.isValidMove(6, 1, 4, 3) << endl;
    cout << "Move (3,1) to (6,4): " << myBishop.isValidMove(3, 1, 6, 4) << endl;
    cout << "move (3,1) to (2,2): " << myBishop.isValidMove(3, 1, 2, 2) << endl;
    cout << "Move (4,3) to (1,2): " << myBishop.isValidMove(4, 3, 1, 2) << endl;

    Pawn whitePawn('W'); // White Sipahi
    Pawn blackPawn('B'); // Black Sipahi

    // Test 1: White ki pehli move (Row 6 se Row 4 par jana - 2 steps) -> Sahi (Output 1)
    cout << "White 2-step start: " << whitePawn.isValidMove(6, 0, 4, 0) << endl;

    // Test 2: White ka aam move (Row 4 se Row 3 par jana - 1 step) -> Sahi (Output 1)
    cout << "White 1-step move: " << whitePawn.isValidMove(4, 0, 3, 0) << endl;

    // Test 3: Black ka aam move (Row 2 se Row 3 par jana - 1 step neechay) -> Sahi (Output 1)
    cout << "Black 1-step move: " << blackPawn.isValidMove(2, 0, 3, 0) << endl;

    // Test 4: White ka peeche jana (Row 4 se Row 5 par wapas jana) -> Ghalat (Output 0)
    cout << "White moving backwards: " << whitePawn.isValidMove(4, 0, 5, 0) << endl;

    Queen myQueen('W'); // White Wazir

    // Test 1: Seedha chalna (Rook style) -> (Output 1 aana chahye)
    cout << "Move straight (0,0) to (0,7): " << myQueen.isValidMove(0, 0, 0, 7) << endl;

    // Test 2: Tircha chalna (Bishop style) -> (Output 1 aana chahye)
    cout << "Move diagonal (4,4) to (7,7): " << myQueen.isValidMove(4, 4, 7, 7) << endl;

    // Test 3: Ghalat move (Ghore/Knight ki tarah L-shape) -> (Output 0 aana chahye)
    cout << "Move L-shape (0,0) to (2,1): " << myQueen.isValidMove(0, 0, 2, 1) << endl;

    King myKing('W'); // White Badshah

    // Test 1: 1 step aage (Seedha) -> Sahi (Output 1)
    cout << "Move 1 step forward (4,4) to (3,4): " << myKing.isValidMove(4, 4, 3, 4) << endl;

    // Test 2: 1 step tircha (Diagonal) -> Sahi (Output 1)
    cout << "Move 1 step diagonal (4,4) to (5,5): " << myKing.isValidMove(4, 4, 5, 5) << endl;

    // Test 3: 2 steps aage jana (Ghalat move) -> Ghalat (Output 0)
    cout << "Move 2 steps forward (4,4) to (2,4): " << myKing.isValidMove(2, 2, 3, 1) << endl;

    return 0;
}