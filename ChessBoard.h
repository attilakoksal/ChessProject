#ifndef CHESSBOARD_H
#define CHESSBOARD_H

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

class ChessBoard
{
    ChessSquare square[8][8];
    ChessColor turn = ChessColor::White;

    void moveKing(ChessSquare *currentSquare, ChessSquare *targetSquare);
    void moveQueen(ChessSquare *currentSquare, ChessSquare *targetSquare);
    void moveBishop(ChessSquare *currentSquare, ChessSquare *targetSquare);
    void moveKnight(ChessSquare *currentSquare, ChessSquare *targetSquare);
    void moveRook(ChessSquare *currentSquare, ChessSquare *targetSquare);
    void movePawn(ChessSquare *currentSquare, ChessSquare *targetSquare);
    bool isValidKing(ChessSquare *currentSquare, ChessSquare *targetSquare);
    bool isValidQueen(ChessSquare *currentSquare, ChessSquare *targetSquare);
    bool isValidBishop(ChessSquare *currentSquare, ChessSquare *targetSquare);
    bool isValidKnight(ChessSquare *currentSquare, ChessSquare *targetSquare);
    bool isValidRook(ChessSquare *currentSquare, ChessSquare *targetSquare);
    bool isValidPawn(ChessSquare *currentSquare, ChessSquare *targetSquare);


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