#include "ChessBoard.h"

using namespace std;

void ChessBoard::moveKing(int oldx, int oldy, int newx, int newy){
    ChessSquare *oldSquare = getSquare(oldx, oldy);
    ChessSquare *newSquare = getSquare(newx, newy);
    newSquare->setOccupied(false);

    if ((oldSquare->isOccupied() == false) || newSquare->isOccupied()){
        cout << "Invalid move, try again." << endl;
        return;
    }

    // Check for valid king movement
    // Assuming we are only allowing the king to move one square in any direction
    int diffx = abs(newx - oldx);
    int diffy = abs(newy - oldy);
    if (diffx > 1 || diffy > 1){
        cout << "Invalid move, try again." << endl;
        return;
    }

    // Move the king to the new square
    newSquare->setPiece(oldSquare->getPiece());
    newSquare->setOccupied(true);
    newSquare->setPiece("K");

    oldSquare->setPiece(" ");
    oldSquare->setOccupied(false);

    // Update the board representation
    board[oldy][oldx]->setPiece(" ");
    board[oldy][oldx]->setOccupied(false);
    board[newy][newx]->setPiece("K");
    board[newy][newx]->setOccupied(true);

    cout << endl << "King moved from " << char(oldx + 'a') << 8 - oldy << " to " << char(newx + 'a') << 8 - newy << endl << endl;
}