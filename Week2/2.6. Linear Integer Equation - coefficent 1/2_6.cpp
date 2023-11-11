#include <iostream>
using namespace std;

const int N = 9;

bool check(int matrix[N][N], int row, int col, int number) {
	for (int i = 0; i < N; i++) {
		if (matrix[row][i] == number || matrix[i][col] == number) {
			return false;
		}
	}
	int row3 = row - row % 3;
	int col3 = col - col % 3;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (matrix[row3 + i][col3 + j] == number) {
				return false;
			}
		}
	} 
	return true;
}

int countSolution(int matrix[N][N]) {
	int col = -1, row = -1;
	bool empty = false;
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (matrix[i][j] == 0) {
				row = i;
				col = j;
				empty = true;
				break;
			}
			
		} 
		if (empty)  break;
	} 
	if (!empty) return 1;
	
	for (int i = 1; i <= 9; i++) {
		if (check(matrix, row, col, i)) {
			matrix[row][col] = i;
			count += countSolution(matrix);
			matrix[row][col] = 0;
		}
	}
	return count;
}


int main() {
	int matrix[N][N];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> matrix[i][j];
		}
	}
	int i = countSolution(matrix);
	cout << i;
}
