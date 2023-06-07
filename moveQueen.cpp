#include "ChessBoard.h"

using namespace std;

void ChessBoard::moveQueen(int oldx, int oldy, int newx, int newy){
    ChessSquare *oldSquare = getSquare(oldx, oldy);
    ChessSquare *newSquare = getSquare(newx, newy);
    newSquare->setOccupied(false);

    if ((oldSquare->isOccupied() == false) || newSquare->isOccupied()){
        cout << "Invalid move, try again." << endl;
        return;
    }

    // Check for valid queen movement
    // Assuming we are only allowing the queen to move horizontally, vertically, or diagonally any number of squares
    if (newx != oldx && newy != oldy && abs(newx - oldx) != abs(newy - oldy)){
        cout << "Invalid move, try again." << endl;
        return;
    }

    // Move the queen to the new square
    newSquare->setPiece(oldSquare->getPiece());
    newSquare->setOccupied(true);
    newSquare->setPiece("Q");

    oldSquare->setPiece(" ");
    oldSquare->setOccupied(false);

    // Update the board representation
    board[oldy][oldx]->setPiece(" ");
    board[oldy][oldx]->setOccupied(false);
    board[newy][newx]->setPiece("Q");
    board[newy][newx]->setOccupied(true);

    cout << endl << "Queen moved from " << char(oldx + 'a') << 8 - oldy << " to " << char(newx + 'a') << 8 - newy << endl << endl;
}