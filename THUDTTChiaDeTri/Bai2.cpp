#include <bits/stdc++.h>
#include <vector>
using namespace std;

void merge(vector<double>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<double> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<double>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void displayList(const vector<double>& arr) {
    cout << "Danh sach sau khi sap xep:" << endl;
    for (double num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<double> numbers = {3.4, 1.2, 5.6, 2.3, 4.7, 0.9, 6.1, 2.8, 4.2, 1.5, 3.9, 5.2, 2.1, 4.5, 1.8};
    int n = numbers.size();
    mergeSort(numbers, 0, n - 1);
    displayList(numbers);

    return 0;
}