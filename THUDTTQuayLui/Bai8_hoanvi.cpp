#include <bits/stdc++.h>
#include <vector>

using namespace std;

void generatePermutations(vector<int>& nums, vector<bool>& used, vector<int>& current, int n) {
    if (current.size() == n) {  
        cout << "\t";
		for (int num : current) {
            cout << num <<" " ;  
        }
        cout << endl;
    } else {
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                used[i] = true;
                current.push_back(nums[i]);

                generatePermutations(nums, used, current, n);

                used[i] = false;
                current.pop_back();
            }
        }
    }
}

void generatePermutations(vector<int>& nums) {
    int n = nums.size();
    vector<bool> used(n, false);  
    vector<int> current;  

    generatePermutations(nums, used, current, n);
}

int main() {
    int n;
    cout << "Nhap so phan tu: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Nhap cac phan tu: "<<endl;
    for (int i = 0; i < n; i++) {
    	cout<<"\t";
        cin >> nums[i];
    }
	cout << "Cac hoan vi cua tap so da nhap la: "<<endl;
    generatePermutations(nums);

    return 0;
}