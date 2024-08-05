#include <bits/stdc++.h>
#include <vector>
#include <limits>
using namespace std;

// Hàm tìm số chẵn nhỏ nhất trong danh sách
int findSmallestEvenNumber(const vector<int>& numbers, int left, int right) {
    if (left == right) {
        if (numbers[left] % 2 == 0) {
            return numbers[left];
        } else {
            return numeric_limits<int>::max(); // Trả về giá trị vô cùng nếu không có số chẵn
        }
    }

    int mid = left + (right - left) / 2;

    int leftMin = findSmallestEvenNumber(numbers, left, mid);
    int rightMin = findSmallestEvenNumber(numbers, mid + 1, right);

    if (leftMin % 2 == 0 && leftMin < rightMin) {
        return leftMin;
    } else if (rightMin % 2 == 0) {
        return rightMin;
    } else {
        return numeric_limits<int>::max(); // Trả về giá trị vô cùng nếu không có số chẵn
    }
}

int main() {
    // Khởi tạo danh sách số nguyên
    vector<int> numbers = {0, 3, 5, 7, 2, 4, 6, 8, 9, 11, 13, 10, 12, 14, 15, 16, 17, 18, 19, 20};

    // Tìm số chẵn nhỏ nhất trong danh sách
    int smallestEven = findSmallestEvenNumber(numbers, 0, numbers.size() - 1);

    // Hiển thị kết quả
   	if (smallestEven != numeric_limits<int>::max()) {
        cout << "So chan nho nhat trong danh sach: " << smallestEven << endl;
    } else {
        cout << "Khong tim thay so chan." << endl;
    }

    return 0;
}