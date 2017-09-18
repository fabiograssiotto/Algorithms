#include <iostream>
using namespace std;

enum MATRIXRESULT {
	MATRIX_OK,
	MATRIX_CHANGEBIT,
	MATRIX_CORRUPT
};

int matrix[101][101];
int changeBitI = 0;
int changeBitJ = 0;

void clearMatrix(int dimension) {
	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {
			matrix[i][j] = 0;
		}
	}
}

bool checkRow(int row, int dimension) {
	// For each row
	int rowSum = 0;
	for (int j = 0; j < dimension; j++) {
		// Get the rowSum.
		rowSum += matrix[row][j];
	}
	if (rowSum % 2 != 0) {
		// Not an even number, this row does not have Parity.
		return false;
	}
	else {
		return true;
	}
}

bool checkCol(int col, int dimension) {
	// For each column
	int colSum = 0;
	for (int line = 0; line < dimension; line++) {
		colSum += matrix[line][col];
	}
	if (colSum % 2 != 0) {
		return false;
	}
	else {
		return true;
	}
}

MATRIXRESULT checkParity(int dimension) {

	MATRIXRESULT ret = MATRIX_OK;

	int numBadRows = 0, numBadCols = 0;
	int badRow = -1, badCol = -1;

	for (int row = 0; row < dimension; row++) {
		if (checkRow(row, dimension) == false) {
			numBadRows++;
			badRow = row;
		}
	}

	// Then all columns
	for (int col = 0; col < dimension; col++) {
		if (checkCol(col, dimension) == false) {
			numBadCols++;
			badCol = col;
		}
	}

	if (numBadCols == 1 && numBadRows == 1) {
		changeBitI = badRow + 1;
		changeBitJ = badCol + 1;
		ret = MATRIX_CHANGEBIT;
	}
	else if (numBadCols + numBadRows == 0) {
		ret = MATRIX_OK;
	}
	else {
		ret = MATRIX_CORRUPT;
	}

	return ret;
}


int main() {

	while (1) {
		int dimension = 0;
		cin >> dimension;
		if (dimension != 0) {
			// New matrix to handle.
			clearMatrix(dimension);
			for (int line = 0; line < dimension; line++) {
				for (int col = 0; col < dimension; col++) {
					cin >> matrix[line][col];
				}
			}
			MATRIXRESULT res = checkParity(dimension);
			if (res == MATRIX_OK) {
				cout << "OK" << endl;
			}
			else if (res == MATRIX_CHANGEBIT) {
				cout << "Change bit (" << changeBitI << "," << changeBitJ << ")" << endl;
			}
			else {
				cout << "Corrupt" << endl;
			}
		}
		else {
			break;
		}
	}
}