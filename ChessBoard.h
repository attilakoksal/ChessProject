#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include "ChessSquare.h"


class ChessBoard
{
  private:
    vector<vector<ChessSquare*>> board;
  public:
    ChessBoard();
    ChessSquare* getSquare(int row, int col) const;
    bool isValidSquare(int row, int col) const;
    void setupBoard();
    void printBoard() const;
    void movePawn(int oldx, int oldy, int newx, int newy);
};

#endif