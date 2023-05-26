#ifndef CHESSSQUARE_H
#define CHESSSQUARE_H

#include <iostream>
#include <cmath>
#include <string>


enum class ChessPiece
{
    King,
    Queen,
    Bishop,
    Knight,
    Rook,
    Pawn,
    Empty
};
enum class ChessColor
{
    White,
    Black,
    None
};

class ChessSquare
{
    ChessPiece piece;
    ChessColor color;
    int x, y;

public:
    ChessSquare();                                             // Constructor for ChessSquare class
    void setSquare(ChessSquare *other);                        // Set the properties of the square based on another ChessSquare object
    void setEmpty();                                           // Set the square to be empty (no piece)
    void setPieceAndColor(ChessPiece piece, ChessColor color); // Set the type and color of the chess piece on the square
    ChessPiece getPiece();                                     // Get the type of chess piece on the square
    ChessColor getColor();                                     // Get the color of the chess piece on the square
    void setX(int newX);                                          // Set the x coordinate of the square
void setY(int newY);                                          // Set the y coordinate of the square
   int getX();                                                // Get the x coordinate of the square
   int getY();                                                // Get the y coordinate of the square
    //ChessSquare* getSquare(int x, int y);                      // Returns a ChessSquare class pointer at position (x, y)                      
};


#endif