#include <iostream>
#include <cmath>
#include <string> 
#include "ChessBoard.h"
#include "ChessSquare.h"

using namespace stsd; 

void ChessBoard::setBoard(){
       //Empty = pieces, none = color // First part will set up empty chess board 
        for(int rows = 0; rows < 8; ++row){
            for (int column = 0; column < 8; ++column){
                ChessSquare[rows][column].setPieceAndColor(EMPTY, NONE)
                ChessSquare[rows][column].setX(column);
                ChessSquare[rows][column].setY(rows);
            }
        }
            //used online chess board picture to figure out the spaces
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

            //doing it separately for pawns because they are repeatable
        for (int columns = 0; columns < 8; ++columns){
            ChessSquare[columns][1].setPieceAndColor(Pawn, White);
        }

        for(int columns = 0; columns < 8; ++columns){
            ChessSquare[columns][6].setPieceAndColor(Pawn, Black);
        
        }
}
        


    