#include "gtest/gtest.h"
#include "ChessBoard.h"
#include "ChessSquare.h"


int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

//check if move is valid (moves the function)
TEST(ChessBoardTest, Bishop_Valid){
	ChessBoard chess_board;
	chess_board.setupBoard();

	chess_board.getSquare(1,1)->setPiece("Bishop");
	EXPECT_NO_THROW(chess_board.moveBishop(1,1,3,3));
}


//check if destination is occupied (does not move the function)
TEST(ChessBoardTest, Bishop_Occupied){
	ChessBoard chess_board;
	chess_board.setupBoard();

	chess_board.getSquare(2,0)->setPiece("Bishop");
	chess_board.getSquare(3,1)->setPiece("Pawn");
	EXPECT_THROW(chess_board.moveBishop(2,0,3,1), std::invalid_argument);
}

//validating move function

TEST(ChessBoardTest, Bishop_Move){
	ChessBoard chess_board;
	chess_board.setupBoard();

	chess_board.getSquare(1,1)->setPiece("Bishop");
	EXPECT_NO_THROW(chess_board.moveBishop(1, 1, 3, 3));
}

//testing for capture
TEST(ChessBoardTest, MoveBishop_capture){
	ChessBoard chess_board;
	
	chess_board.getSquare(1,1)->setPiece("Bishop");
	chess_board.getSquare(1,1)->setOccupied(true);
	chess_board.getSquare(3,3)->setPiece("p");
	chess_board.getSquare(3,3)->setOccupied(true);
	EXPECT_NO_THROW(chess_board.moveBishop(1,1,3,3));
}

