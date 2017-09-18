/*
Check The Check
*/
#include <iostream>
using namespace std;

enum COLOR {
	WHITE,
	BLACK,
	NONE
};

enum CHECK {
	BLACK_CHECK,
	WHITE_CHECK,
	NO_CHECK
};

struct Position {
	int line;
	int col;
	Position() {
		line = -1;
		col = -1;
	}
};

char board[8][8];
// Piece positions
Position wKing, bKing, wKnight1, wKnight2, bKnight1, bKnight2;

bool deathByKnight(COLOR kingColor) {
	// Check if the King is checked by either Knights.
	int lineDiff1, colDiff1, lineDiff2, colDiff2;

	if (kingColor == WHITE) {
		lineDiff1 = abs(wKing.line - bKnight1.line);
		lineDiff2 = abs(wKing.line - bKnight2.line);
		colDiff1 = abs(wKing.col - bKnight1.col);
		colDiff2 = abs(wKing.col - bKnight2.col);
	}
	else {
		lineDiff1 = abs(bKing.line - wKnight1.line);
		lineDiff2 = abs(bKing.line - wKnight2.line);
		colDiff1 = abs(bKing.col - wKnight1.col);
		colDiff2 = abs(bKing.col - wKnight2.col);
	}

	if (((lineDiff1 == 1 && colDiff1 == 2) || (lineDiff1 == 2 && colDiff1 == 1)) ||
		((lineDiff2 == 1 && colDiff2 == 2) || (lineDiff2 == 2 && colDiff1 == 2))) {
		return true;
	}
	else {
		return false;
	}
}

COLOR pieceColor(char c) {
	if (c == '.') {
		return NONE;
	} else if (c >= 'a' && c <= 'z') {
		return BLACK;
	}
	else {
		return WHITE;
	}
}

bool checkRow(COLOR kingColor) {
	if (kingColor == WHITE) {
		// Find first piece horizontally to the left of the king.
		for (int i = wKing.col-1; i > 0; i--) {
			char piece = board[wKing.line][i];
			COLOR color = pieceColor(piece);
			if (color == WHITE) {
				// King is protected
				return false;
			}
			else if (color == BLACK) {
				// Possible threat... 
				if (piece == 'q' || piece == 'r') {
					// Queen or Rook, we are dead.
					return true;
				}
				else {
					return false;
				}

			}
		}
		// And to the right.
		for (int i = wKing.col+1; i < 8; i++) {
			char piece = board[wKing.line][i];
			COLOR color = pieceColor(piece);
			if (color == WHITE) {
				// King is protected
				return false;
			} else if (color == BLACK) {
				// Possible threat... 
				if (piece == 'q' || piece == 'r') {
					// Queen or Rook, we are dead.
					return true;
				}
				else {
					return false;
				}
			}
		}
	}
	else {
		// BLACK KING
		// Find first piece horizontally to the left of the king.
		for (int i = bKing.col - 1; i > 0; i--) {
			char piece = board[bKing.line][i];
			COLOR color = pieceColor(piece);
			if (color == BLACK) {
				// King is protected
				return false;
			}
			else if (color == WHITE) {
				// Possible threat... 
				if (piece == 'Q' || piece == 'R') {
					// Queen or Rook, we are dead.
					return true;
				}
				else {
					return false;
				}

			}
		}
		// And to the right.
		for (int i = bKing.col + 1; i < 8; i++) {
			char piece = board[bKing.line][i];
			COLOR color = pieceColor(piece);
			if (color == BLACK) {
				// King is protected
				return false;
			}
			else if (color == WHITE) {
				// Possible threat... 
				if (piece == 'Q' || piece == 'R') {
					// Queen or Rook, we are dead.
					return true;
				}
				else {
					return false;
				}
			}
		}
	}
	// Nothing found.
	return false;
}

bool checkFile(COLOR kingColor) {
	if (kingColor == WHITE) {
		// Find first piece vertically above the king.
		for (int i = wKing.line - 1; i > 0; i--) {
			char piece = board[i][wKing.col];
			COLOR color = pieceColor(piece);
			if (color == WHITE) {
				// King is protected
				return false;
			}
			else if (color == BLACK) {
				// Possible threat... 
				if (piece == 'q' || piece == 'r') {
					// Queen or Rook, we are dead.
					return true;
				}
				else {
					return false;
				}

			}
		}
		// And below the king.
		for (int i = wKing.line + 1; i < 8; i++) {
			char piece = board[i][wKing.col];
			COLOR color = pieceColor(piece);
			if (color == WHITE) {
				// King is protected
				return false;
			}
			else if (color == BLACK) {
				// Possible threat... 
				if (piece == 'q' || piece == 'r') {
					// Queen or Rook, we are dead.
					return true;
				}
				else {
					return false;
				}
			}
		}
	}
	else {
		// BLACK KING
		// Find first piece vertically above the king.
		for (int i = bKing.line - 1; i > 0; i--) {
			char piece = board[i][bKing.col];
			COLOR color = pieceColor(piece);
			if (color == BLACK) {
				// King is protected
				return false;
			}
			else if (color == WHITE) {
				// Possible threat... 
				if (piece == 'Q' || piece == 'R') {
					// Queen or Rook, we are dead.
					return true;
				}
				else {
					return false;
				}

			}
		}
		// And below the king.
		for (int i = bKing.line + 1; i < 8; i++) {
			char piece = board[i][bKing.col];
			COLOR color = pieceColor(piece);
			if (color == BLACK) {
				// King is protected
				return false;
			}
			else if (color == WHITE) {
				// Possible threat... 
				if (piece == 'Q' || piece == 'R') {
					// Queen or Rook, we are dead.
					return true;
				}
				else {
					return false;
				}
			}
		}
	}
	// Nothing found.
	return false;
}

bool diagPieceCheck(int i, int j, COLOR kingColor) {
	
	char piece = board[i][j];
	COLOR color = pieceColor(piece);

	if (kingColor == WHITE) {
		if (color == WHITE) {
			// King is protected
			return false;
		}
		else if (color == BLACK) {
			// Possible threat... 
			if (piece == 'q' || piece == 'b') {
				// Queen or Bishop, we are dead.
				return true;
			}
			else {
				return false;
			}
		}
	}
	else {
		if (color == BLACK) {
			// King is protected
			return false;
		}
		else if (color == WHITE) {
			// Possible threat... 
			if (piece == 'Q' || piece == 'R') {
				// Queen or Rook, we are dead.
				return true;
			}
			else {
				return false;
			}

		}
	}
}
bool checkDiag(COLOR kingColor) {
	Position king;
	if (kingColor == WHITE) {
		king = wKing;
	}
	else {
		king = bKing;
	}
	
		// Check Diagonal above and to the right of the king
	i = 1;
		while(king.line+i
			
				if (diagPieceCheck(king.line+i, king.col+i, kingColor)) {
					return true;
				}
				else {
					if (board[i][j] == '.') {
						continue;
					}
					else {
						break;
					}
				}
		}
		// Check Diagonal above and to the left of the king
		for (int i = wKing.line - 1; i > 0; i--) {
			for (int j = wKing.col - 1; j > 0; j++)
				if (diagPieceCheck(i, j, kingColor)) {
					return true;
				}
				else {
					if (board[i][j] == '.') {
						continue;
					}
					else {
						break;
					}
				}
		}
		// Check Diagonal below and to the right of the king
		for (int i = wKing.line + 1; i < 8; i++) {
			for (int j = wKing.col + 1; j < 8; j++)
				if (diagPieceCheck(i, j, kingColor)) {
					return true;
				}
				else {
					if (board[i][j] == '.') {
						continue;
					}
					else {
						break;
					}
				}
		}
		// Check Diagonal below and to the left of the king
		for (int i = wKing.line + 1; i < 8; i++) {
			for (int j = wKing.col - 1; j > 0; j++)
				if (diagPieceCheck(i, j, kingColor)) {
					return true;
				}
				else {
					if (board[i][j] == '.') {
						continue;
					}
					else {
						break;
					}
				}
		}
	}
	
}

int main() {
	// Read in Board
	int game = 0;


	while (1) {
		CHECK check = NO_CHECK;
		bool noPieces = true;
		game++;

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				char c;
				cin >> c;
				if (c != '.') {
					// Found at least one piece
					noPieces = false;
					// Save a few pieces positions:
					// White King, Black King and Knights.
					if (c == 'K') {
						wKing.line = i;
						wKing.col = j;
					}
					else if (c == 'k') {
						bKing.line = i;
						bKing.col = j;
					}
					else if (c == 'N') {
						if (wKnight1.line == -1) {
							// First Knight
							wKnight1.line = i;
							wKnight1.col = j;
						}
						else {
							wKnight2.line = i;
							wKnight2.col = j;
						}
					}
					else if (c == 'n') {
						if(bKnight1.line == -1) {
							// First Knight
							bKnight1.line = i;
							bKnight1.col = j;
						}
						else {
							bKnight2.line = i;
							bKnight2.col = j;
						}
					}
				}
				board[i][j] = c;
			}
		}
		if (noPieces) {
			// stop
			break;
		}
		else {
				// Now verify board positions.
				if (deathByKnight(WHITE) || checkRow(WHITE) || checkFile(WHITE) || checkDiag(WHITE)) {
					check = WHITE_CHECK;
				}
				else if (deathByKnight(BLACK) || checkRow(BLACK) || checkFile(BLACK) || checkDiag(BLACK)) {
					check = BLACK_CHECK;
				}

				if (check == BLACK_CHECK) {
					cout << "Game #" << game << ": black king is in check" << endl;
				}
				else if (check == WHITE_CHECK) {
					cout << "Game #" << game << ": white king is in check" << endl;
				}
				else {
					cout << "Game #" << game << ": no king is in check" << endl;
				}
		}
	}
}