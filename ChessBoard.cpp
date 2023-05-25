#include "ChessBoard.h"
using namespace std;

void ChessBoard::move()
{
    int oldx, oldy, newx, newy;
    string mv; 
    bool cont = true;

   while(cont)
   {
        if (turn == WHITE)
        {
            cout << "White's turn: " << endl; 
        }
        else
        {
            cout << "Black's turn: " << endl;
        }

        cout << "Enter a string of 4 numbers in the form of old x, old y, new x, new y: " << endl;
        cin >> mv; 

        oldx = stoi(mv.substr(0, 1)); //turns the move string into sub strings of length one then converts them into ints
        oldy = stoi(mv.substr(1, 1));
        newx = stoi(mv.substr(2, 1));
        newy = stoi(mv.substr(3, 1));

        if (turn==getSquare(oldx, oldy)->getColor()) //extracts the square and see if the turn matches the color of the piece on the square
        {
            if (valid(oldx, oldy, newx, newy) == false)
            {
                cout << "Invlaid move, try again" << endl;
            }
            cont = false; 
        }
        else
        {
            cout << "That is not your piece. " << endl; //turn isnt the same as the color of the piece on the square, invalid move
        }
   }

   if (getSquare(x2, y2)->getPiece() == KING && getSquare(x2, y2)->getColor() == WHITE)
   {
        cout << "Black wins." << endl; 
        return; 
   }
   else if (getSquare(x2, y2)->getPiece() == KING && getSquare(x2, y2)->getColor() == BLACK)
   {
        cout << "White wins. " << endl; 
        retunr;
   }

   if (turn == WHITE)
   {
        turn = BLACK; 
   }
   else
   {
        turn = WHITE;
   }



}

bool ChessBoard::valid(int x1, int y1, int x2, int y2))
{
    if (x1<0 || x1>7 || y1<0 || y1>7 || x2<0 || x2>7 || y2<0 || y2>7 || )
    {
        cout << "Moving out of bounds. " << endl;
        return false; 
    }

    ChessSquare* Old = getSquare(x1, y1);
    ChessSquare* New = getSquare(x2, y2);

    if (Old->getColor() == New->getColor())
    {
        cout << "Cannot land on your own piece. " << endl;
        return false;
    }
}

//get and set square