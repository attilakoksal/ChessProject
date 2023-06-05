#include "ChessBoard.h"

using namespace std;

// directly modifies the board by updating the king's positions and the target square that the king is wanted to go
// isValidKing checks if the movement by the king is valid or not, and if it's valid, then the movement is enacted
// if the movement is invalid, no changes are made to the board, other than an error message

void ChessBoard::moveKing(ChessSquare* currentSquare, ChessSquare* targetSquare){

    if(isValidKing(currentSquare,targetSquare)){
        targetSquare->setSquare(currentSquare);
        currentSquare->setEmpty();

        currentSquare = targetSquare; // updating position
    }
    else{
        cout << "Invalid move. Try again." << endl;
        return;
    }

}