#include <bits/stdc++.h>
using namespace std;
vector<bool> prefixesDivBy5(vector<int>& nums) {
    vector<bool> ans;
    int x = 0;

    for(int bit : nums) {
        x = (x * 2 + bit) % 5;
        ans.push_back(x == 0);
    }
    return ans;
}
int main() {
    vector<int> nums={0,1,1};
    vector<bool> ans=prefixesDivBy5(nums);
    return 0;
}