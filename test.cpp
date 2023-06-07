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

	chess_board.getSquare(2,0)->setPiece("B");
	EXPECT_THROW(chess_board.moveBishop(2,0,4,2), std::invalid_argument);
}


//check if destination is occupied (does not move the function)
TEST(ChessBoardTest, Bishop_occupied){
	ChessBoard chess_board;
	chess_board.setupBoard();

	EXPECT_FALSE(chess_board.getSquare(3,0) -> isOccupied()) ;
}

//validating move function

TEST(ChessBoardTest, BishopMove){
	ChessBoard chess_board;
	chess_board.setupBoard();

	EXPECT_THROW(chess_board.moveBishop(2,0,2,2), std::invalid_argument);
}

//testing for capture

TEST(ChessBoardTest, Bishop_capture){
	ChessBoard chess_board;
	chess_board.setupBoard();

	EXPECT_NO_THROW(chess_board.moveBishop(2, 0, 4, 2));
	EXPECT_NO_THROW(chess_board.moveBishop(5, 3, 7, 1));
}

