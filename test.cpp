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

	chess_board.getSquare(1, 1)->setPiece("Bishop");
	chess_board.getSquare(1, 1)->setOccupied(true);
	chess_board.getSquare(3, 3)->setPiece("p");
	chess_board.getSquare(3, 3)->setOccupied(true);
	EXPECT_NO_THROW(chess_board.moveBishop(1, 1, 3, 3));
}

TEST(ChessBoardTest, Queen_Valid)
{
	ChessBoard chess_board;
	chess_board.setupBoard();
	chess_board.getSquare(3,0)->setPiece("Q");
	EXPECT_NO_THROW(chess_board.moveQueen(3, 0, 3, 5));
}

TEST(ChessBoardTest, Queen_Invalid)
{
	ChessBoard chess_board;
	chess_board.setupBoard();
	chess_board.getSquare(3, 0)->setPiece("Q");
	EXPECT_THROW(chess_board.moveQueen(3, 0, 2, 4), std::invalid_argument);
}

TEST(ChessBoardTest, Queen_Capture)
{
	ChessBoard chess_board;
	chess_board.setupBoard();
	chess_board.getSquare(3, 0)->setPiece("Q"); 
	chess_board.getSquare(3, 3)->setPiece("p"); 

	EXPECT_NO_THROW(chess_board.moveQueen(3, 0, 3, 3));

	EXPECT_FALSE(chess_board.getSquare(3, 0)->isOccupied());
	EXPECT_TRUE(chess_board.getSquare(3, 3)->isOccupied()); 
	EXPECT_EQ("Q", chess_board.getSquare(3, 3)->getPiece());
}

TEST(ChessBoardTest, King_Valid){
	ChessBoard chess_board;
	chess_board.setupBoard();
	chess_board.getSquare(4,0)->setPiece("K");
	EXPECT_NO_THROW(chess_board.moveKing(4, 0, 4, 1));
}

TEST(ChessBoardTest, King_Invalid){
	ChessBoard chess_board;
	chess_board.setupBoard();
	chess_board.getSquare(4, 0)->setPiece("K");
	EXPECT_THROW(chess_board.moveKing(4, 0, 4, 2), std::invalid_argument);
}

TEST(ChessBoardTest, King_Capture){
	ChessBoard chess_board;
	chess_board.setupBoard();
	chess_board.getSquare(4, 0)->setPiece("K"); 
	chess_board.getSquare(4, 1)->setPiece("p"); 

	EXPECT_NO_THROW(chess_board.moveKing(4, 0, 4, 1));

	EXPECT_FALSE(chess_board.getSquare(4, 0)->isOccupied());
	EXPECT_TRUE(chess_board.getSquare(4, 1)->isOccupied()); 
	EXPECT_EQ("K", chess_board.getSquare(4, 1)->getPiece());
}

TEST(ChessBoardTest, Rook_Valid)
{ // VALID ROOK
	ChessBoard chess_board;
	chess_board.setupBoard();

	chess_board.getSquare(0, 0)->setPiece("R");
	EXPECT_NO_THROW(chess_board.moveRook(0, 0, 3, 0));
}
TEST(ChessBoardTest, Rook_Capture)
{ // rook capture
	ChessBoard chess_board;
	chess_board.setupBoard();

	chess_board.getSquare(0, 0)->setPiece("R"); // Rook at (0, 0)
	chess_board.getSquare(0, 2)->setPiece("p"); // Opponent's piece (pawn) at (0, 2)

	EXPECT_NO_THROW(chess_board.moveRook(0, 0, 0, 2)); // Expect no exception to be thrown

	// Verify that the rook has captured the opponent's piece
	EXPECT_FALSE(chess_board.getSquare(0, 0)->isOccupied()); // Rook is no longer at (0, 0)
	EXPECT_TRUE(chess_board.getSquare(0, 2)->isOccupied());	 // Opponent's piece is captured at (0, 2)
	EXPECT_EQ("R", chess_board.getSquare(0, 2)->getPiece()); // The captured piece is a rook
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

TEST(ChessBoardTest, Knight_Capture)
{ // knight capture
	ChessBoard chess_board;
	chess_board.setupBoard();

	chess_board.getSquare(0, 1)->setPiece("N"); // Knight at (0, 1)
	chess_board.getSquare(2, 2)->setPiece("p"); // Opponent's piece (pawn) at (2, 2)

	EXPECT_NO_THROW(chess_board.moveKnight(0, 1, 2, 2)); // Expect no exception to be thrown

	// Verify that the knight has captured the opponent's piece
	EXPECT_FALSE(chess_board.getSquare(0, 1)->isOccupied()); // Knight is no longer at (0, 1)
	EXPECT_TRUE(chess_board.getSquare(2, 2)->isOccupied());	 // Opponent's piece is captured at (2, 2)
	EXPECT_EQ("N", chess_board.getSquare(2, 2)->getPiece()); // The captured piece is a knight
}

TEST(ChessBoardTest, Knight_Invalid)
{ // INVALID KNIGHT MOVEMENT
	ChessBoard chess_board;
	chess_board.setupBoard();

	chess_board.getSquare(2, 1)->setPiece("N"); // Placing a knight on square (2, 1)

	EXPECT_THROW(chess_board.moveKnight(2, 1, 4, 1), std::invalid_argument);
}