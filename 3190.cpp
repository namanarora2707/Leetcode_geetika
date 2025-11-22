#include <bits/stdc++.h>
using namespace std;
int minimumOperations(vector<int>& nums) {
    int operations = 0;
    for(int x : nums){
        if(x % 3 != 0) operations++;  
    }
    return operations;
}
int main() {
    vector<int> nums = {4,7,8,11};
    cout << minimumOperations(nums) << endl;
    return 0;
}