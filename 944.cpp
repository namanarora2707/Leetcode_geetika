#include <bits/stdc++.h>
using namespace std;
int minDeletionSize(vector<string>& strs) {
    int n = strs.size();
    int m = strs[0].size();
    int count = 0;

    for (int col = 0; col < m; col++) {
        for (int row = 0; row < n - 1; row++) {
            if (strs[row][col] > strs[row + 1][col]) {
                count++;
                break;
            }
        }
    }
    return count;
}
int main() {
    vector<string> strs = {"abc", "bce", "cae"};
    cout << minDeletionSize(strs) << endl;
    return 0;
}