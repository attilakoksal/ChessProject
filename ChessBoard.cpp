#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include "ChessBoard.h"
#include "ChessSquare.h"

using namespace std;
/*
void ChessBoard::move()
{
    int oldx, oldy, newx, newy;
    string mv;
    bool cont = true;
    int x2; 
    int y2; 

    while (cont)
    {
        if (turn == ChessColor::White)
        {
            cout << "White's turn: " << endl;
        }
        else
        {
            cout << "Black's turn: " << endl;
        }

        cout << "Enter a string of 4 numbers in the form of old x, old y, new x, new y: " << endl;
        cin >> mv;

        oldx = stoi(mv.substr(0, 1)); // turns the move string into sub strings of length one then converts them into ints
        oldy = stoi(mv.substr(1, 1));
        newx = stoi(mv.substr(2, 1));
        newy = stoi(mv.substr(3, 1));

        if (turn == getSquare(oldx, oldy)->getColor()) // extracts the square and see if the turn matches the color of the piece on the square
        {
            if (valid(oldx, oldy, newx, newy) == false)
            {
                cout << "Invlaid move, try again" << endl;
            }
            cont = false;
        }
        else
        {
            cout << "Not your turn. " << endl; // turn isnt the same as the color of the piece on the square, invalid move
        }

        if (getSquare(x2, y2)->getPiece() == ChessPiece::King && getSquare(x2, y2)->getColor() == ChessColor::White)
        {
            cout << "Black wins." << endl;
            return;
        }
        else if (getSquare(x2, y2)->getPiece() == ChessPiece::King && getSquare(x2, y2)->getColor() == ChessColor::Black)
        {
            cout << "White wins. " << endl;
            return;
        }

        if (turn == ChessColor::White)
        {
            turn = ChessColor::Black;
        }
        else
        {
            turn = ChessColor::White;
        }
    }
}

bool ChessBoard::valid(int x1, int y1, int x2, int y2)
{
    if (x1 < 0 || x1 > 7 || y1 < 0 || y1 > 7 || x2 < 0 || x2 > 7 || y2 < 0 || y2 > 7)
    {
        cout << "Moving out of bounds. " << endl;
        return false;
    }

    ChessSquare *Old = getSquare(x1, y1);
    ChessSquare *New = getSquare(x2, y2);

    if (Old->getColor() == New->getColor())
    {
        cout << "Cannot land on your own piece. " << endl;
        return false;
    }
    return true;
}
*/
void ChessBoard::setBoard()
{
    // Empty = pieces, none = color // First part will set up empty chess board
    for (int rows = 0; rows < 8; ++rows)
    {
        for (int column = 0; column < 8; ++column)
        {
            ChesssSquare[rows][column].setPieceAndColor(ChessPiece::Empty, ChessColor::None);
              ChesssSquare[rows][column].setX(column);
           ChesssSquare[rows][column].setY(rows);
        }
    }
    // used online chess board picture to figure out the spaces
    ChesssSquare[0][0].setPieceAndColor(ChessPiece::Rook, ChessColor::White);
    ChesssSquare[1][0].setPieceAndColor(ChessPiece::Knight, ChessColor::White);
    ChesssSquare[2][0].setPieceAndColor(ChessPiece::Bishop, ChessColor::White);
    ChesssSquare[3][0].setPieceAndColor(ChessPiece::Queen, ChessColor::White);
    ChesssSquare[4][0].setPieceAndColor(ChessPiece::King, ChessColor::White);
    ChesssSquare[5][0].setPieceAndColor(ChessPiece::Bishop, ChessColor::White);
    ChesssSquare[6][0].setPieceAndColor(ChessPiece::Knight, ChessColor::White);
    ChesssSquare[7][0].setPieceAndColor(ChessPiece::Rook, ChessColor::White);

    ChesssSquare[0][7].setPieceAndColor(ChessPiece::Rook, ChessColor::Black);
    ChesssSquare[1][7].setPieceAndColor(ChessPiece::Knight, ChessColor::Black);
    ChesssSquare[2][7].setPieceAndColor(ChessPiece::Bishop, ChessColor::Black);
    ChesssSquare[3][7].setPieceAndColor(ChessPiece::Queen, ChessColor::Black);
    ChesssSquare[4][7].setPieceAndColor(ChessPiece::King, ChessColor::Black);
    ChesssSquare[5][7].setPieceAndColor(ChessPiece::Bishop, ChessColor::Black);
    ChesssSquare[6][7].setPieceAndColor(ChessPiece::Knight, ChessColor::Black);
    ChesssSquare[7][7].setPieceAndColor(ChessPiece::Rook, ChessColor::Black);

    // doing it separately for pawns because they are repeatable
    for (int columns = 0; columns < 8; ++columns)
    {
        ChesssSquare[columns][1].setPieceAndColor(ChessPiece::Pawn, ChessColor::White);
    }

    for (int columns = 0; columns < 8; ++columns)
    {
        ChesssSquare[columns][6].setPieceAndColor(ChessPiece::Pawn, ChessColor::Black);
    }
}
//used stack overflow for the chess baord dimensions. 

void ChessBoard::printBoard()
{
     //   cout << "   ";

    for (int columns = 0; columns < 8; ++columns)
    {
            cout << setw(2) <<  columns << " ";
    }
    cout << endl;

    for (int rows = 0; rows < 8; ++rows)
    {

            cout << setw(2) << rows << " ";

    for (int columns =0; columns < 8; ++columns)
    {
            ChessPiece piece = ChesssSquare[columns][rows].getPiece();
            ChessColor color = ChesssSquare[columns][rows].getColor();

            string piece_structure; // for pieces structure
            string color_structure; // for color strucutre

            if (piece == ChessPiece::Rook)
            {
                piece_structure = "R";
            }

            else if (piece == ChessPiece::Pawn)
            {
                piece_structure = "P";
            }

            else if (piece == ChessPiece::Knight)
            {
                piece_structure = "N";
            }

            else if (piece == ChessPiece::Bishop)
            {
                piece_structure = "B";
            }

            else if (piece == ChessPiece::Queen)
            {
                piece_structure = "Q";
            }

            else if (piece == ChessPiece::King)
            {
                piece_structure = "K";
            }

            // for colors

            if (color == ChessColor::White)
            {
                color_structure = "W";
            }

            else if (color == ChessColor::Black)
            {
                color_structure = "b";
            }

            // Printing the Pieces with corresponding colors

            cout << piece_structure <<  color_structure << "  ";
        }
        cout << endl;

       cout << endl; 
       
    }
}
/*
bool ChessBoard::playGame()
{
	clearScreen();
	printBoard();
    move();
	return true;
}
*/
/*
void ChessBoard::clearScreen()
{
	#ifdef _WIN32
		std::system("cls");
	#else
		
		std::system("clear");
	#endif
}

void ChessBoard::setSquare(ChessSquare* targetSquare, int x, int y){
		ChesssSquare[x][y]= *targetSquare;
	}
*/