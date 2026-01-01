#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        if (n == 1) {
            cout << 1 << "\n";
        } 
        else if (n == 2) {
            cout << 9 << "\n";
        } 
        else {
            long long val = 1LL * (n - 2) * n + (n - 1);
            cout << 5 * val << "\n";
        }
    }
    return 0;
}
