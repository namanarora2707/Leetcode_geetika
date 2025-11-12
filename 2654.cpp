#include <bits/stdc++.h>
using namespace std;
int minOperations(vector<int>& nums) {
    int n = nums.size();
    int countOne = count(nums.begin(), nums.end(), 1);
    if (countOne > 0)
        return n - countOne;
    int minOps = INT_MAX;
    for (int i = 0; i < n; i++) {
        int g = nums[i];
        for (int j = i + 1; j < n; j++) {
            g = gcd(g, nums[j]);
            if (g == 1) {
                minOps = min(minOps, j - i);
                break;
            }
        }
    }
    if (minOps == INT_MAX)
        return -1;
    return minOps + (n - 1);
}
int main() {
    vector<int> nums = {2, 6, 4, 4, 4, 2, 8};
    cout << minOperations(nums) << endl;
    return 0;
}