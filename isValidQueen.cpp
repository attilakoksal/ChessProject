#include "ChessBoard.h"

using namespace std;

bool ChessBoard::isValidQueen(ChessSquare *currentSquare, ChessSquare *targetSquare){

    int currentQueenX = currentSquare->getX();
    int currentQueenY = currentSquare->getY();
    int newQueenX = targetSquare->getX();
    int newQueenY = targetSquare->getY();

    int directionX;
    int directionY;

    // check if the current position of the queen is different than the target position wanted for the queen
    // if it's the same position, invalid move
    if(currentQueenX == newQueenX && currentQueenY == newQueenY){
        return false;
    }

    // check horizontal or vertical movement
    if (currentQueenX == newQueenX || currentQueenY == newQueenY){
        int begin;
        int end;
        int addByOne;

        if(currentQueenX == newQueenX){
            begin = currentQueenY;
            end = newQueenY;
        }
        else{
            begin = currentQueenX;
            end = newQueenX;
        }

        if(end > begin){
            addByOne = 1;
        }
        else{
            addByOne = -1;
        }

        for(int i = begin + addByOne; i != end; i+=addByOne){
            
        }

    }

}