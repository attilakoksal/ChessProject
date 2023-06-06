#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include "ChessBoard.h"
#include "ChessSquare.h"

using namespace std;

ChessBoard::ChessBoard() 
{
    board.resize(8, vector<ChessSquare*>(8, nullptr));
    
    for (int row = 0; row < 8; ++row) 
    {
        for (int col = 0; col < 8; ++col) 
        {
            board[row][col] = new ChessSquare();
        }
    }
}

ChessSquare* ChessBoard::getSquare(int row, int col) const 
{
    if (isValidSquare(row, col)) {
        return board[row][col];
    }
    return nullptr;
}

bool ChessBoard::isValidSquare(int row, int col) const 
{
    return (row >= 0 && row < 8 && col >= 0 && col < 8);
}

void ChessBoard::setupBoard() 
{
    // Set up the starting configuration of the chessboard
    // White Pieces
    board[0][0]->setPiece("R"); // Rook
    board[0][1]->setPiece("N"); // Knight
    board[0][2]->setPiece("B"); // Bishop
    board[0][3]->setPiece("Q"); // Queen
    board[0][4]->setPiece("K"); // King
    board[0][5]->setPiece("B"); // Bishop
    board[0][6]->setPiece("N"); // Knight
    board[0][7]->setPiece("R"); // Rook
    for (int i = 0; i < 8; ++i) {
        board[1][i]->setPiece("P"); // Pawn
    }

    // Black Pieces
    board[7][0]->setPiece("r"); // Rook
    board[7][1]->setPiece("n"); // Knight
    board[7][2]->setPiece("b"); // Bishop
    board[7][3]->setPiece("q"); // Queen
    board[7][4]->setPiece("k"); // King
    board[7][5]->setPiece("b"); // Bishop
    board[7][6]->setPiece("k"); // Knight
    board[7][7]->setPiece("r"); // Rook
    for (int i = 0; i < 8; ++i) {
        board[6][i]->setPiece("p"); // Pawn
    }

    // Set occupied to true for the occupied squares
    for (int row = 0; row < 8; ++row) 
    {
        for (int col = 0; col < 8; ++col) 
        {
            
            ChessSquare* square = board[row][col];
            
            if (square->getPiece() != " ") 
            {
                square->setOccupied(true);
            }
            else
            {
                square->setOccupied(false);
            }
        }
    }
}

void ChessBoard::printBoard() const 
{
    cout << "  a b c d e f g h" << endl;

    for (int row = 0; row < 8; ++row) {
        cout << 8 - row << " ";
        for (int col = 0; col < 8; ++col) {
            ChessSquare* square = board[row][col];
            if (square->isOccupied()) {
                cout << square->getPiece() << " ";
            } else {
                cout << "- ";
            }
        }
        cout << endl;
    }
}

void ChessBoard::movePawn(int oldx, int oldy, int newx, int newy)
{
    ChessSquare* oldSquare = getSquare(oldx, oldy);
    ChessSquare* newSquare = getSquare(newx, newy);
    newSquare->setOccupied(false);
    
    if ((oldSquare->isOccupied() == false) || newSquare->isOccupied()) {
        
        cout << "Invalid move, try again." << endl;
        return;
    }

    // Check for valid pawn movement
    // Assuming we are only allowing the pawn to move forward one square
    if (newy != oldy + 1) {
        cout << "Invalid move, try again." << endl << endl;
        return;
    }
    

    // Move the pawn to the new square
    newSquare->setPiece(oldSquare->getPiece());
    newSquare->setOccupied(true);
    newSquare->setPiece("P");
    
    oldSquare->setPiece(" ");
    oldSquare->setOccupied(false);

    // Update the board representation
    board[oldy][oldx]->setPiece(" ");
    board[oldy][oldx]->setOccupied(false);
    board[newy][newx]->setPiece("P");
    board[newy][newx]->setOccupied(true);
    

    cout << endl << "Pawn moved from " << char(oldx + 'a') << 8 - oldy << " to " << char(newx + 'a') << 8 - newy << endl << endl;
}