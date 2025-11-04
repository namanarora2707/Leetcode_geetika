#include <bits/stdc++.h>
using namespace std;
vector<int> findXSum(vector<int>& nums, int k, int x) {
    int n = nums.size();
    vector<int> ans;
    unordered_map<int, int> freq;
    for (int i = 0; i < k; i++)
        freq[nums[i]]++;

    auto computeXSum = [&](unordered_map<int, int>& freqMap) {
        vector<pair<int, int>> v;
        for (auto &p : freqMap)
            v.push_back({p.first, p.second});
        sort(v.begin(), v.end(), [&](auto &a, auto &b) {
            if (a.second == b.second)
                return a.first > b.first;
            return a.second > b.second;
        });
        unordered_set<int> keep;
        for (int i = 0; i < min(x, (int)v.size()); i++)
            keep.insert(v[i].first);
        
        int sum = 0;
        for (auto &p : freqMap) {
            if (keep.count(p.first))
                sum += p.first * p.second;
        }
        return sum;
    };
    ans.push_back(computeXSum(freq));
    for (int i = k; i < n; i++) {
        int out = nums[i - k];
        if (--freq[out] == 0)
            freq.erase(out);
        freq[nums[i]]++;
        ans.push_back(computeXSum(freq));
    }

    return ans;
}
int main() {
    vector<int> nums={1,2,3,4,5};
    int k=2,x=3;
    vector<int> ans=findXSum(nums,k,x);
    for(auto it:ans)cout<<it<<" ";
    return 0;
}