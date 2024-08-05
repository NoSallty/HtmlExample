#include <bits/stdc++.h>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col) {
    int N = board.size();

    for (int c = 0; c < col; c++) {
        if (board[row][c] == 1) {
            return false;
        }
    }

    for (int r = row, c = col; r >= 0 && c >= 0; r--, c--) {
        if (board[r][c] == 1) {
            return false;
        }
    }

    for (int r = row, c = col; r < N && c >= 0; r++, c--) {
        if (board[r][c] == 1) {
            return false;
        }
    }

    return true;
}

bool solveNQueens(vector<vector<int>>& board, int col) {
    int N = board.size();

    if (col >= N) {
        return true;
    }

    for (int row = 0; row < N; row++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1; 

            if (solveNQueens(board, col + 1)) {
                return true;
            }

            board[row][col] = 0;
        }
    }

    return false;
}

void solveNQueens(int N) {
    vector<vector<int>> board(N, vector<int>(N, 0));

    if (solveNQueens(board, 0)) {
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < N; col++) {
                cout << board[row][col] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "Khong ton tai loi giai!" << endl;
    }
}

int main() {
    int N;
    cout << "Nhap kich thuoc cua ban co (N x N): ";
    cin >> N;

    solveNQueens(N);

    return 0;
}