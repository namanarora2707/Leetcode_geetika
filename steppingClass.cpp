#include <bits/stdc++.h>
using namespace std;
 
int main() {
    
 
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
 
        int awakeTill = -1;  // last index till which sleeping is forbidden
        int sleepCount = 0;
 
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                awakeTill = max(awakeTill, i + k);
            } else {
                if (i > awakeTill) {
                    sleepCount++;
                }
            }
        }
 
        cout << sleepCount << "\n";
    }
 
    return 0;
}