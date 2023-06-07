#include "gtest/gtest.h"
#include "ChessBoard.h"
#include "ChessSquare.h"

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

//for bishop: used google premier test page
//is user entering a valid coordinates for bishop movement 
TEST(ChessBoardTest, IsinputValid_Bishop)
{
	//chess_board is object
	ChessBoard chess_board;
	chess_board.setupBoard();
	chess_board.getSquare(1,1)->setPiece("Bishop"); //sets up board with specific coordinates
	EXPECT_NO_THROW(chess_board.moveBishop(1,1,3,3));
}

//did bishop moved when accurate coordinates were added
TEST(ChessBoardTest, IsMoveValid_Bishop){
	ChessBoard chess_board;
	chess_board.setupBoard();
	chess_board.getSquare(1,1)->setPiece("Bishop"); //sets up "Bishop" at 1,1 on chess board and then move to 3,3 
	EXPECT_NO_THROW(chess_board.moveBishop(1, 1, 3, 3));
}

//test case for initial pos of Bishop on chess board
TEST(ChessBoardTest, IsInitialPos_Bishop)
{
	ChessBoard chess_board;
	chess_board.setupBoard();

	EXPECT_FALSE(chess_board.getSquare(3, 0)->isOccupied());
}


//this test case check if bishop moves and captures the pawn
//basically tests the whole logic of bishop program
TEST(ChessBoardTest, IsMove_CaptureValid_Bishop)
{
	ChessBoard chess_board;
	chess_board.getSquare(1,1)->setPiece("Bishop"); //places the bishop at 1,1 and sets that square to true
	chess_board.getSquare(1,1)->setOccupied(true);
	chess_board.getSquare(3,3)->setPiece("p"); //places the pawn at 3,3 and sets it to true
	chess_board.getSquare(3,3)->setOccupied(true);
	EXPECT_NO_THROW(chess_board.moveBishop(1,1,3,3)); //makes a move
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

