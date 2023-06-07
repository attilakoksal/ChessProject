#include "gtest/gtest.h"
#include "ChessBoard.h"
#include "ChessSquare.h"

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

// check if move is valid (moves the function)
TEST(ChessBoardTest, Bishop_Valid)
{
	ChessBoard chess_board;
	chess_board.setupBoard();

	chess_board.getSquare(2, 0)->setPiece("B");
	EXPECT_THROW(chess_board.moveBishop(2, 0, 4, 2), std::invalid_argument);
}

// check if destination is occupied (does not move the function)
TEST(ChessBoardTest, Bishop_occupied)
{
	ChessBoard chess_board;
	chess_board.setupBoard();

	EXPECT_FALSE(chess_board.getSquare(3, 0)->isOccupied());
}

// validating move function

TEST(ChessBoardTest, BishopMove)
{
	ChessBoard chess_board;
	chess_board.setupBoard();

	EXPECT_THROW(chess_board.moveBishop(2, 0, 2, 2), std::invalid_argument);
}

// testing for capture

TEST(ChessBoardTest, Bishop_capture)
{
	ChessBoard chess_board;
	chess_board.setupBoard();

	EXPECT_NO_THROW(chess_board.moveBishop(2, 0, 4, 2));
	EXPECT_NO_THROW(chess_board.moveBishop(5, 3, 7, 1));
}

TEST(ChessBoardTest, Queen_Valid)
{
	ChessBoard chess_board;
	chess_board.setupBoard();

	chess_board.getSquare(3, 0)->setPiece("Q");

	// move to be invalid
	EXPECT_THROW(chess_board.moveQueen(3, 0, 4, 2), std::invalid_argument);
}

TEST(ChessBoardTest, Queen_Occupied)
{
	ChessBoard chess_board;
	chess_board.setupBoard();

	// if square is occupied or not
	EXPECT_FALSE(chess_board.getSquare(1, 0)->isOccupied());
}

TEST(ChessBoardTest, Queen_Move)
{
	ChessBoard chess_board;
	chess_board.setupBoard();

	EXPECT_THROW(chess_board.moveQueen(3, 0, 3, 3), std::invalid_argument);
}

TEST(ChessBoardTest, Queen_Capture)
{
	ChessBoard chess_board;
	chess_board.setupBoard();

	EXPECT_NO_THROW(chess_board.moveQueen(2, 0, 4, 2));
	EXPECT_NO_THROW(chess_board.moveQueen(5, 3, 7, 1));
}
TEST(ChessBoardTest, Rook_Valid)
{ // VALID ROOK
	ChessBoard chess_board;
	chess_board.setupBoard();

	chess_board.getSquare(0, 0)->setPiece("R");
	EXPECT_NO_THROW(chess_board.moveRook(0, 0, 3, 0));
}
TEST(ChessBoardTest, Rook_Occupied)
{ // OCCUPIED POS ROOK
	ChessBoard chess_board;
	chess_board.setupBoard();

	chess_board.getSquare(0, 0)->setPiece("R");
	chess_board.getSquare(3, 0)->setPiece("P");
	EXPECT_THROW(chess_board.moveRook(0, 0, 3, 0), std::invalid_argument);
}
TEST(ChessBoardTest, Rook_Invalid)
{ // INVALID ROOK MOVEMENT
	ChessBoard chess_board;
	chess_board.setupBoard();

	chess_board.getSquare(0, 0)->setPiece("R");
	EXPECT_THROW(chess_board.moveRook(0, 0, 2, 2), std::invalid_argument);
}
TEST(ChessBoardTest, Knight_Valid)
{ // VALID KNIGHT MOVEMENT
	ChessBoard chess_board;
	chess_board.setupBoard();

	chess_board.getSquare(0, 1)->setPiece("N");
	EXPECT_NO_THROW(chess_board.moveKnight(0, 1, 2, 2));
}

TEST(ChessBoardTest, Knight_Occupied)
{ // OCCUPIED POS KNIGHT
	ChessBoard chess_board;
	chess_board.setupBoard();

	chess_board.getSquare(0, 1)->setPiece("N");
	chess_board.getSquare(2, 2)->setPiece("P");
	EXPECT_THROW(chess_board.moveKnight(0, 1, 2, 2), std::invalid_argument);
}

TEST(ChessBoardTest, Knight_Invalid)
{ // INVALID KNIGHT MOVEMENT
	ChessBoard chess_board;
	chess_board.setupBoard();

	chess_board.getSquare(2, 1)->setPiece("N"); // Placing a knight on square (2, 1)

	EXPECT_THROW(chess_board.moveKnight(2, 1, 4, 1), std::invalid_argument);
}