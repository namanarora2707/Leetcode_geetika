#include <bits/stdc++.h>
using namespace std;
int minDeletionSize(vector<string>& strs) {
    int n = strs.size();
    int m = strs[0].size();
    
    vector<int> dp(m, 1); 
    
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < j; i++) {
            bool ok = true;
            for (int r = 0; r < n; r++) {
                if (strs[r][i] > strs[r][j]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                dp[j] = max(dp[j], dp[i] + 1);
            }
        }
    }
    
    int maxKeep = *max_element(dp.begin(), dp.end());
    return m - maxKeep;
}
int main() {
    vector<string> strs = {"abc","bce","cae"};
    cout << minDeletionSize(strs) << endl;
    return 0;
}