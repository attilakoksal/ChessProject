#include "ChessBoard.h"

using namespace std;

// directly modifies the board by updating the queen's positions and the target square that the queen is wanted to go
// isValidQueen checks if the movement by the queen is valid or not, and if it's valid, then the movement is enacted
// if the movement is invalid, no changes are made to the board, other than an error message

void ChessBoard::moveQueen(ChessSquare* currentSquare, ChessSquare* targetSquare){

    if(isValidQueen(currentSquare,targetSquare)){
        targetSquare->setSquare(currentSquare);
        currentSquare->setEmpty();
    }

}