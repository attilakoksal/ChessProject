#include "ChessBoard.h"

using namespace std;

// checks for occupied squares in the path

bool ChessBoard::isValidQueen(ChessSquare *currentSquare, ChessSquare *targetSquare){

    int currentQueenX = currentSquare->getX();
    int currentQueenY = currentSquare->getY();
    int newQueenX = targetSquare->getX();
    int newQueenY = targetSquare->getY();

    // check if the current position of the queen is different than the target position wanted for the queen
    // if it's the same position, invalid move
    if(currentQueenX == newQueenX && currentQueenY == newQueenY){
        return false;
    }

    // check movement if queen is moving horizontally, vertically, or diagonally
    int diffX = abs(newQueenX - currentQueenX);
    int diffY = abs(newQueenY - currentQueenY);

    // diffX == 0 if queen is moving horizontally
    // diffY == 0 if queen is moving vertically
    // diffX == diffY if queen is moving diagonally

    if(diffX == 0 || diffY == 0 || diffX == diffY){
        
        int addX;
        int addY;
        if(diffX > 0){
            addX = 1;
        }
        else{
            addX = -1;
        }
        if(diffY > 0){
            addY = 1;
        }
        else{
            addY = -1;
        }

        // calculates the coordinates of the squares being checked based on iteration stage and increment values
        for(int i = 1; i < diffX || i < diffY; i++){
            
            int checkedSquareX = currentQueenX + (addX * i); // X coordinate of square being checked
            int checkedSquareY = currentQueenY + (addY * i); // Y coordinate of square being checked

            if(ChesssSquare[checkedSquareX][checkedSquareY].getColor() != NONE){ // if occupied square is encountered
                return false; // invalid movement, occupied square
            }

        }
        return true;

    }
    return false; // invalid movement, nor horizontal, vertical, or diagonal
}