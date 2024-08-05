#include <bits/stdc++.h>
#include <vector>
using namespace std;

// Hàm tính tổng các số dương trong danh sách
double sumPositiveNumbers(const vector<double>& numbers, int left, int right) {
    if (left == right) {
        if (numbers[left] > 0) {
            return numbers[left];
        } else {
            return 0;
        }
    }

    int mid = left + (right - left) / 2;

    double leftSum = sumPositiveNumbers(numbers, left, mid);
    double rightSum = sumPositiveNumbers(numbers, mid + 1, right);

    return leftSum + rightSum;
}

int main() {
    // Khởi tạo danh sách số thực
    vector<double> numbers = {1.5, -2.3, 4.7, -0.9, 3.2, 5.6, -1.2, 2.8, 0.6, -3.1, 6.4, -4.0, 2.1, -5.2, 3.9, -0.5, 1.7, -2.8, 4.3, -6.1};

    // Tính tổng các số dương trong danh sách
    double sum = sumPositiveNumbers(numbers, 0, numbers.size() - 1);

    // Hiển thị kết quả
    cout << "Tong cac so duong trong danh sach: " << sum << endl;

    return 0;
}