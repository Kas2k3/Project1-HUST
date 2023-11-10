#include <stdio.h>
#include <stdlib.h>

#define N 9

int count = 0;

int is_valid(int t[N][N], int row, int col, int num) {

    for (int i = 0; i < N; i++) {
        if (t[row][i] == num || t[i][col] == num) {
            return 0;
        }
    }

    int start_row = row - (row % 3);
    int start_col = col - (col % 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (t[i + start_row][j + start_col] == num) {
                return 0;
            }
        }
    }

    return 1;
}

void solve_sudoku(int t[N][N], int row, int col) {
    if (row == N - 1 && col == N) {
        count++;
        return;
    }

    if (col == N) {

        row++;
        col = 0;
    }

    if (t[row][col] != 0) {

        solve_sudoku(t, row, col + 1);
        return;
    }


    for (int num = 1; num <= N; num++) {
        if (is_valid(t, row, col, num)) {
            t[row][col] = num;
            solve_sudoku(t, row, col + 1);
            t[row][col] = 0; 
        }
    }
}

int main() {
    int t[N][N];


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &t[i][j]);
        }
    }

    solve_sudoku(t, 0, 0);


    printf("%d\n", count);

    return 0;
}
