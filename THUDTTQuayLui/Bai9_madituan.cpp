#include <bits/stdc++.h>
#include <vector>

using namespace std;

bool isSafe(int x, int y, int N, vector<vector<int>>& board) {
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
}

void printBoard(vector<vector<int>>& board) {
    int N = board.size();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << board[i][j] << "\t";
        }
        cout << endl;
    }
}

bool solveKnightTour(int x, int y, int moveCount, int N, vector<vector<int>>& board,
                     vector<int>& moveX, vector<int>& moveY) {
    if (moveCount == N * N) {
        printBoard(board);
        return true;
    }

    for (int i = 0; i < 8; ++i) {
        int nextX = x + moveX[i];
        int nextY = y + moveY[i];
        if (isSafe(nextX, nextY, N, board)) {
            board[nextX][nextY] = moveCount;
            if (solveKnightTour(nextX, nextY, moveCount + 1, N, board, moveX, moveY)) {
                return true;
            }
            board[nextX][nextY] = -1;  
        }
    }

    return false;
}

void knightTour(int N) {
    vector<vector<int>> board(N, vector<int>(N, -1)); 
    vector<int> moveX = {2, 1, -1, -2, -2, -1, 1, 2};  
    vector<int> moveY = {1, 2, 2, 1, -1, -2, -2, -1};  

    int startX = 0; 
    int startY = 0;
    int moveCount = 0;

    board[startX][startY] = moveCount;  

    if (!solveKnightTour(startX, startY, moveCount + 1, N, board, moveX, moveY)) {
        cout << "Khong co loi giai!" << endl;
    }
}

int main() {
    int N;
    cout << "Nhap kich thuoc ban co (N x N): ";
    cin >> N;

    knightTour(N);

    return 0;
}