#include <iostream>
#include <vector>

using namespace std;

class ChessSquare {
private:
    bool occupied;
    string piece;

public:
    ChessSquare(){
        occupied = false; 
        piece = " ";
    }

    bool isOccupied() const {
        return occupied;
    }

    void setOccupied(bool value) {
        occupied = value;
    }

    string getPiece() const {
        return piece;
    }

    void setPiece(const string& pieceName) {
        piece = pieceName;
    }
};



class ChessBoard {
private:
    vector<vector<ChessSquare*>> board;

public:
    ChessBoard() 
    {
        board.resize(8, vector<ChessSquare*>(8, nullptr));
        
        for (int row = 0; row < 8; ++row) 
        {
            for (int col = 0; col < 8; ++col) 
            {
                board[row][col] = new ChessSquare();
            }
        }
    }

    ChessSquare* getSquare(int row, int col) const 
    {
        if (isValidSquare(row, col)) {
            return board[row][col];
        }
        return nullptr;
    }

    bool isValidSquare(int row, int col) const 
    {
        return (row >= 0 && row < 8 && col >= 0 && col < 8);
    }

    void setupBoard() {
        // Set up the starting configuration of the chessboard
        // White Pieces
        board[0][0]->setPiece("R"); // Rook
        board[0][1]->setPiece("N"); // Knight
        board[0][2]->setPiece("B"); // Bishop
        board[0][3]->setPiece("Q"); // Queen
        board[0][4]->setPiece("K"); // King
        board[0][5]->setPiece("B"); // Bishop
        board[0][6]->setPiece("N"); // Knight
        board[0][7]->setPiece("R"); // Rook
        for (int i = 0; i < 8; ++i) {
            board[1][i]->setPiece("P"); // Pawn
        }

        // Black Pieces
        board[7][0]->setPiece("r"); // Rook
        board[7][1]->setPiece("n"); // Knight
        board[7][2]->setPiece("b"); // Bishop
        board[7][3]->setPiece("q"); // Queen
        board[7][4]->setPiece("k"); // King
        board[7][5]->setPiece("b"); // Bishop
        board[7][6]->setPiece("k"); // Knight
        board[7][7]->setPiece("r"); // Rook
        for (int i = 0; i < 8; ++i) {
            board[6][i]->setPiece("p"); // Pawn
        }

        // Set occupied to true for the occupied squares
        for (int row = 0; row < 8; ++row) 
        {
            for (int col = 0; col < 8; ++col) 
            {
                
                ChessSquare* square = board[row][col];
                
                if (square->getPiece() != " ") 
                {
                    square->setOccupied(true);
                }
                else
                {
                    square->setOccupied(false);
                }
            }
        }
    }

    void printBoard() const {
        cout << "  a b c d e f g h" << endl;

        for (int row = 0; row < 8; ++row) {
            cout << 8 - row << " ";
            for (int col = 0; col < 8; ++col) {
                ChessSquare* square = board[row][col];
                if (square->isOccupied()) {
                    cout << square->getPiece() << " ";
                } else {
                    cout << "- ";
                }
            }
            cout << endl;
        }
    }
    
    void movePawn(int oldx, int oldy, int newx, int newy)
    {
    ChessSquare* oldSquare = getSquare(oldx, oldy);
    ChessSquare* newSquare = getSquare(newx, newy);
    newSquare->setOccupied(false);
    
    if ((oldSquare->isOccupied() == false) || newSquare->isOccupied()) {
        
        cout << "Invalid move, try again." << endl;
        return;
    }

    // Check for valid pawn movement
    // Assuming we are only allowing the pawn to move forward one square
    if (newy != oldy + 1) {
        cout << "Invalid move, try again." << endl << endl;
        return;
    }
    

    // Move the pawn to the new square
    newSquare->setPiece(oldSquare->getPiece());
    newSquare->setOccupied(true);
    newSquare->setPiece("P");
    
    oldSquare->setPiece(" ");
    oldSquare->setOccupied(false);

    // Update the board representation
    board[oldy][oldx]->setPiece(" ");
    board[oldy][oldx]->setOccupied(false);
    board[newy][newx]->setPiece("P");
    board[newy][newx]->setOccupied(true);
    

    cout << endl << "Pawn moved from " << char(oldx + 'a') << 8 - oldy << " to " << char(newx + 'a') << 8 - newy << endl << endl;
}



void moveRook(int oldx, int oldy, int newx, int newy) {
    ChessSquare* oldSquare = getSquare(oldx, oldy);
    ChessSquare* newSquare = getSquare(newx, newy);

    if (!oldSquare->isOccupied() || (newSquare->isOccupied() && isupper(oldSquare->getPiece()[0]) == isupper(newSquare->getPiece()[0]))) {
        cout << "Invalid move, try again." << endl;
        return;
    }

    // Check for valid rook movement
    if (oldx != newx && oldy != newy) {
        cout << "Invalid move, try again." << endl << endl;
        return;
    }

    // Check if the destination square is occupied by a piece of the opposite color
    if (newSquare->isOccupied() && isupper(oldSquare->getPiece()[0]) != isupper(newSquare->getPiece()[0])) {
        cout << "Capturing " << newSquare->getPiece() << endl;
    }

    // Move the rook to the new square
    newSquare->setPiece(oldSquare->getPiece());
    newSquare->setOccupied(true);
    oldSquare->setPiece(" ");
    oldSquare->setOccupied(false);

    // Update the board representation
    board[oldy][oldx]->setPiece(" ");
    board[oldy][oldx]->setOccupied(false);
    board[newy][newx]->setPiece("R");
    board[newy][newx]->setOccupied(true);

    cout << endl << "Rook moved from " << char(oldx + 'a') << 8 - oldy << " to " << char(newx + 'a') << 8 - newy << endl << endl;
}


void moveKnight(int oldx, int oldy, int newx, int newy) {
    ChessSquare* oldSquare = getSquare(oldx, oldy);
    ChessSquare* newSquare = getSquare(newx, newy);

    if (!oldSquare->isOccupied()) {
        cout << "Invalid move, try again." << endl;
        return;
    }

    // Check for valid knight movement
    int dx = abs(newx - oldx);
    int dy = abs(newy - oldy);
    if (!((dx == 1 && dy == 2) || (dx == 2 && dy == 1))) {
        cout << "Invalid move, try again." << endl << endl;
        return;
    }

// Check if the destination square is occupied by a piece of the same color
if (newSquare->isOccupied() && (isupper(newSquare->getPiece()[0]) == isupper(oldSquare->getPiece()[0]))) {
    cout << "Invalid move, try again." << endl << endl;
    return;
}

// Check if the destination square is occupied by a piece of the opposite color
if (newSquare->isOccupied() && (isupper(newSquare->getPiece()[0]) != isupper(oldSquare->getPiece()[0]))) {
    cout << "Capturing " << newSquare->getPiece() << endl;
}
    // Move the knight to the new square
    newSquare->setPiece(oldSquare->getPiece());
    newSquare->setOccupied(true);
    oldSquare->setPiece(" ");
    oldSquare->setOccupied(false);

    // Update the board representation
    board[oldy][oldx]->setPiece(" ");
    board[oldy][oldx]->setOccupied(false);
    board[newy][newx]->setPiece("N");
    board[newy][newx]->setOccupied(true);

    cout << endl << "Knight moved from " << char(oldx + 'a') << 8 - oldy << " to " << char(newx + 'a') << 8 - newy << endl << endl;
}

void moveQueen(int oldx, int oldy, int newx, int newy){

    ChessSquare* oldSquare = getSquare(oldx,oldy);
    ChessSquare* newSquare = getSquare(newx,newy);

    if (!oldSquare->isOccupied() || (newSquare->isOccupied() && isupper(oldSquare->getPiece()[0]) == isupper(newSquare->getPiece()[0]))) {
        cout << "Invalid move, try again." << endl;
        return;
    }

    // Check for valid queen movement
    if (oldx != newx && oldy != newy && abs(oldx - newx) != abs(oldy - newy)) {
        cout << "Invalid move, try again." << endl << endl;
        return;
    }

    // Check if the destination square is occupied by a piece of the opposite color
    if (newSquare->isOccupied() && isupper(oldSquare->getPiece()[0]) != isupper(newSquare->getPiece()[0])) {
        cout << "Capturing " << newSquare->getPiece() << endl;
    }

    // Move the queen to the new square
    newSquare->setPiece(oldSquare->getPiece());
    newSquare->setOccupied(true);
    oldSquare->setPiece(" ");
    oldSquare->setOccupied(false);

    // Update the board representation
    board[oldy][oldx]->setPiece(" ");
    board[oldy][oldx]->setOccupied(false);
    board[newy][newx]->setPiece("Q");
    board[newy][newx]->setOccupied(true);

    cout << endl << "Queen moved from " << char(oldx + 'a') << 8 - oldy << " to " << char(newx + 'a') << 8 - newy << endl << endl;

}

};


int main() {
    ChessBoard board;
    board.setupBoard();
    board.printBoard();
    
    
    board.movePawn(1, 1, 1, 2);
    board.printBoard();
   


    board.moveRook(0, 7, 4, 7);
    board.printBoard();
   

    board.setupBoard();
    board.printBoard();
    
    
    board.moveKnight(1, 0, 2, 2);
    board.printBoard();
    
    board.setupBoard();
    board.printBoard();

    board.moveQueen(3, 0, 3, 4);
    board.printBoard();
    
    return 0;
}

