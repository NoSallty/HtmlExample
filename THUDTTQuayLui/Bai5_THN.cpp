#include <bits/stdc++.h>

using namespace std;

void TowerOfHanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        cout << "Di chuyen dia 1 tu cot " << source << " sang cot " << destination << std::endl;
        return;
    }

    TowerOfHanoi(n - 1, source, auxiliary, destination);

    cout << "Di chuyen dia " << n << " tu cot " << source << " sang cot " << destination << std::endl;

    TowerOfHanoi(n - 1, auxiliary, destination, source);
}

int main() {
    int n = 4;
    char source = 'A'; 
    char destination = 'C'; 
    char auxiliary = 'B'; 

    TowerOfHanoi(n, source, destination, auxiliary);

    return 0;
}