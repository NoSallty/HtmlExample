#include <bits/stdc++.h>
#include <vector>

using namespace std;

bool isSafe(int row, int col, vector<int>& queens) {
    for (int i = 0; i < row; ++i) {
        if (queens[i] == col || queens[i] - col == i - row || queens[i] - col == row - i) {
            return false;
        }
    }
    return true;
}

void solveNQueens(int row, int n, vector<int>& queens, vector<vector<string>>& solutions) {
    if (row == n) {  
        vector<string> solution(n, string(n, '.'));  
        for (int i = 0; i < n; ++i) {
            solution[i][queens[i]] = 'Q'; 
        }
        solutions.push_back(solution);
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (isSafe(row, col, queens)) {
            queens[row] = col; 
            solveNQueens(row + 1, n, queens, solutions);
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> solutions;
    vector<int> queens(n, -1);  

    solveNQueens(0, n, queens, solutions);

    return solutions;
}

int main() {
    int n;
    cout << "Nhap kich thuoc cua ban co (n x n): ";
    cin >> n;

    vector<vector<string>> solutions = solveNQueens(n);

    int numSolutions = solutions.size();
    cout << "So luong loi giai: " << numSolutions << endl << endl;

    for (int i = 0; i < numSolutions; ++i) {
        cout << "Loi giai " << i + 1 << ":" << endl;
        for (const string& row : solutions[i]) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}