#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int l, a, b;
        cin >> l >> a >> b;

        int g = __gcd(l, b);
        int steps = l / g;

        int ans = 0;
        for (int k = 0; k < steps; k++) {
            int pos = (a + 1LL * k * b) % l;
            ans = max(ans, pos);
        }

        cout << ans << "\n";
    }
    return 0;
}
