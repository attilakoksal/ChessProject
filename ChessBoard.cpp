#include <iostream>
#include <cmath>
#include <string>
#include "ChessBoard.h"
#include "ChessSquare.h"

using namespace std;

void ChessBoard::move()
{
    int oldx, oldy, newx, newy;
    string mv;
    bool cont = true;

    while (cont)
    {
        if (turn == White)
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

        if (getSquare(x2, y2)->getPiece() == King && getSquare(x2, y2)->getColor() == White)
        {
            cout << "Black wins." << endl;
            return;
        }
        else if (getSquare(x2, y2)->getPiece() == King && getSquare(x2, y2)->getColor() == Black)
        {
            cout << "White wins. " << endl;
            retunr;
        }

        if (turn == White)
        {
            turn = Black;
        }
        else
        {
            turn = White;
        }
    }
}

bool ChessBoard::valid(int x1, int y1, int x2, int y2)
{
    if (x1 < 0 || x1 > 7 || y1 < 0 || y1 > 7 || x2 < 0 || x2 > 7 || y2 < 0 || y2 > 7 ||)
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
}

void ChessBoard::setBoard()
{
    // Empty = pieces, none = color // First part will set up empty chess board
    for (int rows = 0; rows < 8; ++row)
    {
        for (int column = 0; column < 8; ++column)
        {
            ChessSquare[rows][column].setPieceAndColor(EMPTY, NONE)
                ChessSquare[rows][column]
                    .setX(column);
            ChessSquare[rows][column].setY(rows);
        }
    }
    // used online chess board picture to figure out the spaces
    ChessSquare[0][0].setPieceAndColor(Rook, White);
    ChessSquare[1][0].setPieceAndColor(Knight, White);
    ChessSquare[2][0].setPieceAndColor(Bishop, White);
    ChessSquare[3][0].setPieceAndColor(Queen, White);
    ChessSquare[4][0].setPieceAndColor(King, White);
    ChessSquare[5][0].setPieceAndColor(Bishop, White);
    ChessSquare[6][0].setPieceAndColor(Knight, White);
    ChessSquare[7][0].setPieceAndColor(Rook, White);

    ChessSquare[0][7].setPieceAndColor(Rook, Black);
    ChessSquare[1][7].setPieceAndColor(Knight, Black);
    ChessSquare[2][7].setPieceAndColor(Bishop, Black);
    ChessSquare[3][7].setPieceAndColor(Queen, Black);
    ChessSquare[4][7].setPieceAndColor(King, Black);
    ChessSquare[5][7].setPieceAndColor(Bishop, Black);
    ChessSquare[6][7].setPieceAndColor(Knight, Black);
    ChessSquare[7][7].setPieceAndColor(Rook, Black);

    // doing it separately for pawns because they are repeatable
    for (int columns = 0; columns < 8; ++columns)
    {
        ChessSquare[columns][1].setPieceAndColor(Pawn, White);
    }

    for (int columns = 0; columns < 8; ++columns)
    {
        ChessSquare[columns][6].setPieceAndColor(Pawn, Black);
    }
}

void ChessBoard::printBoard()
{
    for (int rows = 0; rows < 8; ++rows)
    {
        for (int columns = 0; columns < 8; ++rows)
        {

            piece piece = ChessSquare[Rows][Columns].getPiece();
            color color = ChessSquare[Rows][Columns].getColor();

            string piece_strucutre; // for pieces structure
            string color_strucutre; // for color strucutre

            if (piece == Rook)
            {
                piece_structure = "R";
            }

            else if (piece == Pawn)
            {
                piece_structre = "P";
            }

            else if (piece == Rook)
            {
                piece_structure = "N";
            }

            else if (piece == Bishop)
            {
                piece_structure = "B";
            }

            else if (piece == Queen)
            {
                piece_strucutre = "Q";
            }

            else if (piece == King)
            {
                piece_structure = "K";
            }

            // for colors

            if (color == White)
            {
                color_structure = "w"
            }

            else if (color == Black)
            {
                color_structure = "b"
            }

            // Printing the Pieces with corresponding colors

            cout << piece_structure << color_structure << " ";
        }
        cout << endl;
    }
}

bool ChessBoard::playGame()
{
	clearScreen();
	printBoard();
	return doMove();
}

void ChessBoard::clearScreen()
{
	#ifdef _WIN32
		std::system("cls");
	#else
		
		std::system("clear");
	#endif
}

void ChessBoard::setSquare(Square * targetSquare, int x, int y){
		square[x][y]= *targetSquare;
	}
