#include <bits/stdc++.h>
using namespace std;

// Hàm tính a mũ n
double power(double a, int n) {
    if (n == 0) {
        return 1;
    }

    double temp = power(a, n / 2);
    if (n % 2 == 0) {
        return temp * temp;
    } else {
        if (n > 0) {
            return a * temp * temp;
        } else {
            return (temp * temp) / a;
        }
    }
}

int main() {
    double a;
    int n;

    // Nhập số thực a và số nguyên dương n
    cout << "Nhap so thuc a: ";
    cin >> a;
    cout << "Nhap so nguyen duong n: ";
    cin >> n;

    // Tính giá trị a mũ n
    double result = power(a, n);

    // Hiển thị kết quả
    cout << "Gia tri " << a << " mu " << n << " = " << result << endl;

    return 0;
}