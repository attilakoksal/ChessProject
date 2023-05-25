#include "ChessSquare.h"

using namespace std;

ChessSquare::ChessSquare(){
    piece = Empty;
    color = None;
}

void ChessSquare::setSquare(ChessSquare *other){
    piece = other->getPiece();
    color = other->getColor();
}

void ChessSquare::setEmpty(){
    piece = Empty;
    color = None;
}

void ChessSquare::setPieceAndColor(ChessPiece piece, ChessColor color){
    piece = piece;
    color = color;
}

ChessPiece ChessSquare::getPiece(){
    return piece;
}

ChessColor ChessSquare::getColor(){
    return color;
}

void ChessSquare::setX(int x){
    x = x;
}

void ChessSquare::setY(int y){
    y = y;
}
    
int ChessSquare::getX(){
    return x;
}
    
int ChessSquare::getY(){
    return y;
}