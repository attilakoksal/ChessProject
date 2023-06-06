#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <vector>
#include "ChessBoard.h"
#include "ChessSquare.h"

using namespace std;

ChessBoard::ChessBoard()
{
    board.resize(8, vector<ChessSquare *>(8, nullptr));

    for (int row = 0; row < 8; ++row)
    {
        for (int col = 0; col < 8; ++col)
        {
            board[row][col] = new ChessSquare();
        }
    }
}

ChessSquare *ChessBoard::getSquare(int row, int col) const
{
    if (isValidSquare(row, col))
    {
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
    for (int i = 0; i < 8; ++i)
    {
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
    for (int i = 0; i < 8; ++i)
    {
        board[6][i]->setPiece("p"); // Pawn
    }

    // Set occupied to true for the occupied squares
    for (int row = 0; row < 8; ++row)
    {
        for (int col = 0; col < 8; ++col)
        {

            ChessSquare *square = board[row][col];

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
// used stack overflow for the chess baord dimensions.

void ChessBoard::printBoard() const
{
    cout << "  a b c d e f g h" << endl;

    for (int row = 0; row < 8; ++row)
    {
        cout << 8 - row << " ";
        for (int col = 0; col < 8; ++col)
        {
            ChessSquare *square = board[row][col];
            if (square->isOccupied())
            {
                cout << square->getPiece() << " ";
            }
            else
            {
                cout << "- ";
            }
            cout << "   ";
            for (char columns = 'a'; columns <= 'f'; ++columns)
            {
                cout << setw(2.6) << columns << "  ";
            }
            cout << endl;

            

                cout << endl;
            }
        }
    }
void ChessBoard::movePawn(int oldx, int oldy, int newx, int newy)
{
    ChessSquare *oldSquare = getSquare(oldx, oldy);
    ChessSquare *newSquare = getSquare(newx, newy);
    newSquare->setOccupied(false);

    if ((oldSquare->isOccupied() == false) || newSquare->isOccupied())
    {

        cout << "Invalid move, try again." << endl;
        return;
    }

    // Check for valid pawn movement
    // Assuming we are only allowing the pawn to move forward one square
    if (newy != oldy + 1)
    {
        cout << "Invalid move, try again." << endl
             << endl;
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

    cout << endl
         << "Pawn moved from " << char(oldx + 'a') << 8 - oldy << " to " << char(newx + 'a') << 8 - newy << endl
         << endl;
}

void ChessBoard::moveRook(int oldx, int oldy, int newx, int newy)
{
    ChessSquare *oldSquare = getSquare(oldx, oldy);
    ChessSquare *newSquare = getSquare(newx, newy);

    if (!oldSquare->isOccupied() || (newSquare->isOccupied() && isupper(oldSquare->getPiece()[0]) == isupper(newSquare->getPiece()[0])))
    {
        cout << "Invalid move, try again." << endl;
        return;
    }

    // Check for valid rook movement
    if (oldx != newx && oldy != newy)
    {
        cout << "Invalid move, try again." << endl
             << endl;
        return;
    }

    // Check if the destination square is occupied by a piece of the opposite color
    if (newSquare->isOccupied() && isupper(oldSquare->getPiece()[0]) != isupper(newSquare->getPiece()[0]))
    {
        cout << "Capturing " << newSquare->getPiece() << endl;
    }

    // Move the rook to the new square
    newSquare->setPiece(oldSquare->getPiece());
    newSquare->setOccupied(true);
    oldSquare->setPiece(" ");
    oldSquare->setOccupied(false);

    // Update the board representation
    board[oldy][oldx]->setPiece(" ");
    board[oldy][oldx]->setOccupied(false);
    board[newy][newx]->setPiece("R");
    board[newy][newx]->setOccupied(true);

    cout << endl
         << "Rook moved from " << char(oldx + 'a') << 8 - oldy << " to " << char(newx + 'a') << 8 - newy << endl
         << endl;
}

void ChessBoard::moveKnight(int oldx, int oldy, int newx, int newy)
{
    ChessSquare *oldSquare = getSquare(oldx, oldy);
    ChessSquare *newSquare = getSquare(newx, newy);

    if (!oldSquare->isOccupied())
    {
        cout << "Invalid move, try again." << endl;
        return;
    }

    // Check for valid knight movement
    int dx = abs(newx - oldx);
    int dy = abs(newy - oldy);
    if (!((dx == 1 && dy == 2) || (dx == 2 && dy == 1)))
    {
        cout << "Invalid move, try again." << endl
             << endl;
        return;
    }

    // Check if the destination square is occupied by a piece of the same color
    if (newSquare->isOccupied() && (isupper(newSquare->getPiece()[0]) == isupper(oldSquare->getPiece()[0])))
    {
        cout << "Invalid move, try again." << endl
             << endl;
        return;
    }

    // Check if the destination square is occupied by a piece of the opposite color
    if (newSquare->isOccupied() && (isupper(newSquare->getPiece()[0]) != isupper(oldSquare->getPiece()[0])))
    {
        cout << "Capturing " << newSquare->getPiece() << endl;
    }
    // Move the knight to the new square
    newSquare->setPiece(oldSquare->getPiece());
    newSquare->setOccupied(true);
    oldSquare->setPiece(" ");
    oldSquare->setOccupied(false);

    // Update the board representation
    board[oldy][oldx]->setPiece(" ");
    board[oldy][oldx]->setOccupied(false);
    board[newy][newx]->setPiece("N");
    board[newy][newx]->setOccupied(true);

    cout << endl << "Knight moved from " << char(oldx + 'a') << 8 - oldy << " to " << char(newx + 'a') << 8 - newy << endl << endl;
}
void moveBishop(int oldx, int oldy, int newx, int newy){
    ChessSquare *oldSquare = getSquare(oldx, oldy);
    ChessSquare *newSquare = getSquare(newx, newy);

    //checks if its is occupied
        if(!oldSquare -> isOccupied()) {
            cout << "Invalid move, try again" << endl;
            return;
        }
    //checks for bishop moves(valid)
    int dx = abs(newx - oldx); //for horizontal
    int dy = abs(newy-oldy); // for vertical

        if(dx!= dy) {
            cout << "Invalid move, try again" << endl;
        }
    //checks for moving the bishop
    int x_bishop; //horizontal move
    int y_bishop;  //vertical move

    //it checks if bishop should move right or left
    //used stack_overflow 
    if(newx > oldx){
        x_bishop = 1; //righ
    }
    else {
        x_bishop = -1; //left
    }

    if(newy > oldy){
        y_bishop = 1;
    }
    else {
        y_bishop = -1;
    }

    // Since bishop can't jump, it will check for the way
    int x_way;
    int y_way;

    x_way = oldx + x_bishop;
    y_way = oldy + y_bishop;

    while(x_way != newx && y_way != newy){
        if(getSquare(x_way, y_way)->isOccupied()){
            cout << "Obstacle on the way, try again" << endl;
            return;
        }
        x_way += x_bishop;
        y_way += y_bishop;
    }

    // it will check if destination is same color

    if(newSquare -> isOccupied() && (isupper(newSquare -> getPiece()[0]) == isupper(oldSquare -> getPiece()[0]))){
        cout << "Invalid move, try again" << endl; 
    }
    // it will check if destination is occupied by different color

    if(newSquare->isOccupied() && isupper(oldSquare->getPiece()[0]) != isupper(newSquare -> getPiece()[0])){
        cout << "Capturing " << newSquare-> getPiece() << endl;
    }

    //for moving bishop to new place

    newSquare->setPiece(oldSquare -> getPiece());
    newSquare->setOccupied(true);
    oldSquare->setPiece(" ");
    oldSquare-> setOccupied(false);

    //updating the board with new pieces
    board[oldy][oldx]->setPiece(" ");
    board[oldy][oldx]->setOccupied(false);
    board[newy][newx]->setPiece(oldSquare->getPiece());
    board[newy][newx]->setOccupied(true); 

    cout << endl << "Bishop moved from " << char(oldx + 'a') << 8 - oldy << " to " << char(newx + 'a') << 8 - newy << endl << endl;

    
}