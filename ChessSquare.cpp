#include "ChessSquare.h"
#include "ChessBoard.h"
using namespace std;

ChessSquare::ChessSquare(){
   piece = ChessPiece::Empty;
   color = ChessColor::None;
}

void ChessSquare::setSquare(ChessSquare *other){
    piece = other->getPiece();
    color = other->getColor();
}

void ChessSquare::setEmpty(){
    piece = ChessPiece::Empty;
    color = ChessColor::None;
}

void ChessSquare::setPieceAndColor(ChessPiece newpiece, ChessColor newcolor){
    piece = newpiece;
    color = newcolor;
}

ChessPiece ChessSquare::getPiece(){
    return piece;
}

ChessColor ChessSquare::getColor(){
    return color;
}

void ChessSquare::setX(int newX){
   x = newX;
}

void ChessSquare::setY(int newY){
    y = newY;
}
    
int ChessSquare::getX(){
    return x;
}
    
int ChessSquare::getY(){
    return y;
}
/*
ChessSquare* getSquare(int x, int y)
{
    return new ChessSquare();
}
*/