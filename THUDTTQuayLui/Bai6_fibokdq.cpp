#include <bits/stdc++.h>
#include <stack>

using namespace std;

struct Move {
    int n; 
    char source; 
    char destination; 
    char auxiliary; 

    Move(int _n, char _source, char _destination, char _auxiliary):n(_n), source(_source), destination(_destination), auxiliary(_auxiliary) {}
};

void TowerOfHanoi(int n, char source, char destination, char auxiliary) {
    stack<Move> moves;

    moves.push(Move(n, source, destination, auxiliary));

    while (!moves.empty()) {
        Move currentMove = moves.top();
        moves.pop();

        int currentN = currentMove.n;
        char currentSource = currentMove.source;
        char currentDestination = currentMove.destination;
        char currentAuxiliary = currentMove.auxiliary;

        if (currentN == 1) {
            cout << "Di chuyen dia tu cot " << currentSource << " sang cot " << currentDestination << endl;
        } else {
            moves.push(Move(currentN - 1, currentAuxiliary, currentDestination, currentSource));
            moves.push(Move(1, currentSource, currentDestination, currentAuxiliary));
            moves.push(Move(currentN - 1, currentSource, currentAuxiliary, currentDestination));
        }
    }
}

int main() {
    int n = 4; 
    char source = 'A';
    char destination = 'C'; 
    char auxiliary = 'B'; 

    TowerOfHanoi(n, source, destination, auxiliary);

    return 0;
}