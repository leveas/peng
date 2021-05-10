#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ansnums;

void dfsnums(vector<vector<int>>& nums, vector<int> singlenum, int index) {
    if(singlenum.size() == nums.size()) {
        ansnums.push_back(singlenum);
        return;
    }
    for(int i = 0 ; i < nums[index].size() ; i++) {
        singlenum.push_back(nums[index][i]);
        dfsnums(nums, singlenum, index + 1);
        singlenum.pop_back();
    }
}

int main() {
    vector<vector<int>> nums{{3}, {1, 2}, {4, 5}};
    vector<int> singlenum;
    dfsnums(nums, singlenum, 0);
    for(int i = 0 ; i < ansnums.size() ; i++) {
        for(int j = 0 ; j < ansnums[i].size() ; j++) {
            cout << ansnums[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

