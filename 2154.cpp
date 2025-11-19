#include <bits/stdc++.h>
using namespace std;
int findFinalValue(vector<int>& nums, int original) {
    unordered_set<int> s(nums.begin(), nums.end());
    while (s.find(original) != s.end()) {
        original *= 2;
    }

    return original;
}
int main() {
    vector<int> nums={5,3,6,10,12};
    int original=3;
    cout<<findFinalValue(nums,original)<<endl; 
    return 0;
}