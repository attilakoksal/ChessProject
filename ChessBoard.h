#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <iostream>
#include <cmath>
#include <string>
#include "ChessSquare.h"


class ChessBoard
{
    ChessSquare ChesssSquare[8][8];
    ChessColor turn = ChessColor::White;

    bool moveKing(ChessSquare *currentSquare, ChessSquare *targetSquare);
    bool moveQueen(ChessSquare *currentSquare, ChessSquare *targetSquare);
    bool moveBishop(ChessSquare *currentSquare, ChessSquare *targetSquare);
    bool moveKnight(ChessSquare *currentSquare, ChessSquare *targetSquare);
    bool moveRook(ChessSquare *currentSquare, ChessSquare *targetSquare);
    bool movePawn(ChessSquare *currentSquare, ChessSquare *targetSquare);
    bool makeMove(int startX, int startY, int endX, int endY);
    void printBoard();
    bool valid(int x1, int y1, int x2, int y2);

public:
    ChessSquare *getSquare(int x, int y);              // Get the ChessSquare object at the specified coordinates
    void setSquare(ChessSquare *square, int x, int y); // Set the ChessSquare object at the specified coordinates
    void move();                                     // takes players move
    void setBoard();
    void clearScreen();                                   // sets up board in starting config
    bool playGame();                                   // starts game
};

#endif