#include "ChessSquare.h"
#include "ChessBoard.h"
using namespace std;

ChessSquare::ChessSquare()
{
   occupied=false;
   piece=" ";
}

bool ChessSquare::isOccupied() const
{
    return occupied;
}

void ChessSquare::setOccupied(bool value)
{
    occupied=value;
}

string ChessSquare::getPiece() const
{
    return piece;
}

void ChessSquare::setPiece(const string& pieceName)
{
    piece=pieceName;
}

