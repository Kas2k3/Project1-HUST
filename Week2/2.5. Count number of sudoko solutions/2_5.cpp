#include <stdio.h>
#include <stdlib.h>

#define N 9

int count = 0;

//Ham kiem tra gia tri thoa man
int is_valid(int t[N][N], int row, int col, int num) {
    //Kiem tra num da xuat hien o hang va cot nao chua
    for (int i = 0; i < N; i++) {
        if (t[row][i] == num || t[i][col] == num) {
            return 0;
        }
    }

    //Xet cac o sub-grid 3x3
    int start_row = row - (row % 3);
    int start_col = col - (col % 3);
    //Kiem tra co ton tai (row, col) trong sub-grid 3x3 khong
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (t[i + start_row][j + start_col] == num) {
                return 0;
            }
        }
    }
    //Neu thoa man thi danh dau da dat gia tri vao o do
    return 1;
}

void solve_sudoku(int t[N][N], int row, int col) {
    //Khi da dien het cac hang va cot thi tang bien dem
    if (row == N - 1 && col == N) {
        count++;
        return;
    }

    //Neu da dien het cac cot thi chuyen sang hang ke tiep
    if (col == N) {
        row++;
        col = 0;
    }

    //Neu da ton tai gia tri thi chuyen den cot tiep theo
    if (t[row][col] != 0) {
        solve_sudoku(t, row, col + 1);
        return;
    }

    //Thu lan luot cac gia tri tu 1-9 neu nhu chua ton tai gia tri
    for (int num = 1; num <= N; num++) {
        if (is_valid(t, row, col, num)) {
            t[row][col] = num;
            solve_sudoku(t, row, col + 1);
            t[row][col] = 0; //backtracking de quay lai o truoc do 
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
