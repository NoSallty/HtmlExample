#include <iostream>
#include <vector>
using namespace std;

void combinations(const vector<char>& items, int k, vector<char>& combination, int start_index)
{
    if (combination.size() == k)
    {
        for (char c : combination)
        {
            cout << c << " ";
        }
        cout << endl;
        return;
    }

    for (int i = start_index; i < items.size(); i++)
    {
        combination.push_back(items[i]);
        combinations(items, k, combination, i + 1);
        combination.pop_back();
    }
}

int combinations(int n, int k)
{
    if (k == 0 || k == n)
        return 1;
    else
        return combinations(n - 1, k - 1) + combinations(n - 1, k);
}

int main()
{
    vector<char> items = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
    int k = 6;
    vector<char> combination;

    cout << "Cac cach lay:" << endl;
    combinations(items, k, combination, 0);

    int total_combinations = combinations(items.size(), k);
    cout << "So cach lay: " << total_combinations << endl;

    return 0;
}