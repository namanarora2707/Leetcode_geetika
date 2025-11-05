#include <bits/stdc++.h>
using namespace std;
struct cmp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        if (a.first == b.first)
            return a.second > b.second; 
        return a.first > b.first;       
    }
};
vector<long long> findXSum(vector<int>& nums, int k, int x) {
    int n = nums.size();
    unordered_map<int,int> freq;
    freq.reserve(2 * k);

    set<pair<int,int>, cmp> A, B;  
    long long sumA = 0;            

    auto erasePairIfExists = [&](int f, int v) {
        if (f <= 0) return;
        pair<int,int> p = {f, v};
        auto itA = A.find(p);
        if (itA != A.end()) {
            sumA -= 1LL * f * v;
            A.erase(itA);
        } else {
            auto itB = B.find(p);
            if (itB != B.end()) B.erase(itB);
        }
    };

    auto insertIntoB = [&](int f, int v) {
        if (f > 0) B.insert({f, v});
    };

    auto rebalance = [&]() {
        while ((int)A.size() < min(x, (int)(A.size() + B.size())) && !B.empty()) {
            auto it = B.begin();
            auto p = *it;
            B.erase(it);
            A.insert(p);
            sumA += 1LL * p.first * p.second;
        }
        while ((int)A.size() > x) {
            auto it = prev(A.end());
            auto p = *it;
            A.erase(it);
            sumA -= 1LL * p.first * p.second;
            B.insert(p);
        }
        while (!A.empty() && !B.empty()) {
            auto bestB = *B.begin();
            auto worstA = *prev(A.end());
            if (cmp()(bestB, worstA)) {
                B.erase(B.begin());
                A.erase(prev(A.end()));
                A.insert(bestB);
                B.insert(worstA);
                sumA += 1LL * bestB.first * bestB.second;
                sumA -= 1LL * worstA.first * worstA.second;
            } else break;
        }
    };
    for (int i = 0; i < k; i++) freq[nums[i]]++;
    for (auto& kv : freq) B.insert({kv.second, kv.first});
    rebalance();

    vector<long long> ans;
    ans.reserve(n - k + 1);
    ans.push_back(sumA);
    for (int i = k; i < n; i++) {
        int outv = nums[i - k];
        int inv = nums[i];
        int oldf_out = freq[outv];
        erasePairIfExists(oldf_out, outv);
        if (--freq[outv] == 0) freq.erase(outv);
        else insertIntoB(freq[outv], outv);
        int oldf_in = freq.count(inv) ? freq[inv] : 0;
        if (oldf_in > 0) erasePairIfExists(oldf_in, inv);
        freq[inv] = oldf_in + 1;
        insertIntoB(freq[inv], inv);

        rebalance();
        ans.push_back(sumA);
    }

    return ans;
}
int main() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    vector<long long> ans = findXSum(nums, k, x);
    for (long long a : ans) cout << a << " ";
    return 0;
}