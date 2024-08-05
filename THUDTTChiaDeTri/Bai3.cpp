#include <bits/stdc++.h>
#include <vector>
using namespace std;

double findMax(const vector<double>& numbers, int left, int right) {
    if (left == right) {
        return numbers[left];
    }

    int mid = left + (right - left) / 2;
    double maxLeft = findMax(numbers, left, mid);
    double maxRight = findMax(numbers, mid + 1, right);

    return max(maxLeft, maxRight);
}

int main() {
    vector<double> numbers = {3.4, 1.2, 5.6, 2.3, 4.7, 0.9, 6.1, 2.8, 4.2, 1.5, 3.9, 5.2, 2.1, 4.5, 1.8};
    double maxNumber = findMax(numbers, 0, numbers.size() - 1);
    cout << "Gia tri lon nhat trong danh sach: " << maxNumber << endl;

    return 0;
}