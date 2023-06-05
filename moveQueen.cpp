#include "ChessBoard.h"

using namespace std;

void moveQueen(int oldx, int oldy, int newx, int newy){

    ChessSquare* oldSquare = getSquare(oldx,oldy);
    ChessSquare* newSquare = getSquare(newx,newy);

    if (!oldSquare->isOccupied() || (newSquare->isOccupied() && isupper(oldSquare->getPiece()[0]) == isupper(newSquare->getPiece()[0]))) {
        cout << "Invalid move, try again." << endl;
        return;
    }

    // Check for valid queen movement
    if (oldx != newx && oldy != newy && abs(oldx - newx) != abs(oldy - newy)) {
        cout << "Invalid move, try again." << endl << endl;
        return;
    }

    // Check if the destination square is occupied by a piece of the opposite color
    if (newSquare->isOccupied() && isupper(oldSquare->getPiece()[0]) != isupper(newSquare->getPiece()[0])) {
        cout << "Capturing " << newSquare->getPiece() << endl;
    }

    // Move the queen to the new square
    newSquare->setPiece(oldSquare->getPiece());
    newSquare->setOccupied(true);
    oldSquare->setPiece(" ");
    oldSquare->setOccupied(false);

    // Update the board representation
    board[oldy][oldx]->setPiece(" ");
    board[oldy][oldx]->setOccupied(false);
    board[newy][newx]->setPiece("Q");
    board[newy][newx]->setOccupied(true);

    cout << endl << "Queen moved from " << char(oldx + 'a') << 8 - oldy << " to " << char(newx + 'a') << 8 - newy << endl << endl;

}