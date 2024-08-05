#include <bits/stdc++.h>
#include <vector>

using namespace std;

void generateBinaryHelper(vector<int>& sequence, int n, int i) {
    if (i == n) {
    	cout<<"[ ";
        for (int num : sequence) {
            cout << num << "";
        }
        cout<<" ]";
        cout << endl;
    } else {
        sequence[i] = 0;
        generateBinaryHelper(sequence, n, i + 1);

        sequence[i] = 1;
        generateBinaryHelper(sequence, n, i + 1);
    }
}

void generateBinarySequence(int n) {
    vector<int> sequence(n, 0); 

    generateBinaryHelper(sequence, n, 0);
}

int main() {
    int n;
    cout << "Nhap so ky tu trong day nhi phan: ";
    cin >> n;

    generateBinarySequence(n);

    return 0;
}