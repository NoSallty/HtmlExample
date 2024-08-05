#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int totalArrangements = 0;

void seatingArrangements(const vector<string>& people, const vector<char>& seats, vector<string>& arrangement, vector<bool>& usedSeats)
{
    if (arrangement.size() == seats.size())
    {
        totalArrangements++;
        for (int i = 0; i < arrangement.size(); i++)
        {
            cout << "Nguoi " << arrangement[i] << " ngoi tren ghe " << seats[i] << endl;
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < people.size(); i++)
    {
        if (!usedSeats[i])
        {
            usedSeats[i] = true;
            arrangement.push_back(people[i]);
            seatingArrangements(people, seats, arrangement, usedSeats);
            arrangement.pop_back();
            usedSeats[i] = false;
        }
    }
}

int main()
{
    vector<string> people = { "Tung", "Cuc", "Truc", "Mai" };
    vector<char> seats = { 'A', 'B', 'C', 'D' };
    vector<string> arrangement;
    vector<bool> usedSeats(people.size(), false);

    cout << "Cac cach xep:" << endl;
    seatingArrangements(people, seats, arrangement, usedSeats);

    cout << "Tong so cach xep: " << totalArrangements << endl;

    return 0;
}