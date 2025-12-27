#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    vector<int> answers;

    while (t--) {
        int n;
        cin >> n;

        vector<int> cnt(101, 0);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            cnt[x]++;
        }

        int mex = 0;
        while (cnt[mex] > 0) mex++;

        answers.push_back(mex);
    }

    
    for (int x : answers) {
        cout << x << "\n";
    }

    return 0;
}
