#include "ChessBoard.h"

using namespace std;

bool ChessBoard::isValidQueen(ChessSquare *currentSquare, ChessSquare *targetSquare){

    int currentQueenX = currentSquare->getX();
    int currentQueenY = currentSquare->getY();
    int newQueenX = targetSquare->getX();
    int newQueenY = targetSquare->getY();

    int directionX;
    int directionY;

    

}