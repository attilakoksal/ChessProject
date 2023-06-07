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


TEST(ChessBoardTest, King_Valid){
	ChessBoard chess_board;
	chess_board.setupBoard();

	chess_board.getSquare(4,0)->setPiece("K");

	// move king to a valid position
	EXPECT_NO_THROW(chess_board.moveKing(4,0,5,1),std::invalid_argument);		
}

TEST(ChessBoardTest, King_Occupied){
	ChessBoard chess_board;
	chess_board.setupBoard();

	// if square is occupied or not
	EXPECT_FALSE(chess_board.getSquare(5,0)->isOccupied());
}

TEST(ChessBoardTest, King_Move){
	ChessBoard chess_board;
	chess_board.setupBoard();

	EXPECT_THROW(chess_board.moveKing(4,0,4,1),std::invalid_argument);
}

TEST(ChessBoardTest, King_Capture){
	ChessBoard chess_board;
	chess_board.setupBoard();

	EXPECT_NO_THROW(chess_board.moveKing(0,3,1,4));
	EXPECT_NO_THROW(chess_board.moveKing(3,3,4,2));
}