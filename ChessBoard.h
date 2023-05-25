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

    bool moveKing(ChessSquare *currentSquare, ChessSquare *targetSquare);
    bool moveQueen(ChessSquare *currentSquare, ChessSquare *targetSquare);
    bool moveBishop(ChessSquare *currentSquare, ChessSquare *targetSquare);
    bool moveKnight(ChessSquare *currentSquare, ChessSquare *targetSquare);
    bool moveRook(ChessSquare *currentSquare, ChessSquare *targetSquare);
    bool movePawn(ChessSquare *currentSquare, ChessSquare *targetSquare);
    bool makeMove(int startX, int startY, int endX, int endY);
    void printBoard();

public:
    ChessSquare *getSquare(int x, int y);              // Get the ChessSquare object at the specified coordinates
    void setSquare(ChessSquare *square, int x, int y); // Set the ChessSquare object at the specified coordinates
    bool doMove();                                     // takes players move
    void setBoard();                                   // sets up board in starting config
    bool playGame();                                   // starts game
};