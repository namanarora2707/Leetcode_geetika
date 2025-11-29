#include <bits/stdc++.h>
using namespace std;
int minOperations(vector<int>& nums, int k) {
    int ans=0;
    for(int i=0;i<nums.size();i++){
        ans+=nums[i];
    }
    return ans%k;
}
int main() {
    vector<int> nums={3,7,4,5};
    int k=9;
    cout<<minOperations(nums,k)<<endl;
    return 0;
}