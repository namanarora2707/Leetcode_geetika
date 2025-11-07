#include <bits/stdc++.h>
using namespace std;
bool canAchieve(long long target, const vector<long long>& power, int r, long long k) {
    int n = power.size();
    vector<long long> diff(n + 1, 0);
    long long used = 0;
    long long currAdd = 0;

    for (int i = 0; i < n; ++i) {
        currAdd += diff[i];
        long long currPower = power[i] + currAdd;
        if (currPower < target) {
            long long need = target - currPower;
            used += need;
            if (used > k) return false;
            int pos = min(n - 1, i + r);
            int end = min(n - 1, pos + r); 
            currAdd += need;
            diff[end + 1] -= need;
        }
    }
    return true;
}
long long maxPower(vector<int>& stations, int r, int k) {
    int n = stations.size();
    vector<long long> pref(n + 1, 0);
    for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + stations[i];

    vector<long long> power(n, 0);
    for (int i = 0; i < n; ++i) {
        int L = max(0, i - r);
        int R = min(n - 1, i + r);
        power[i] = pref[R + 1] - pref[L];
    }

    long long low = 0;
    long long high = *max_element(power.begin(), power.end()) + k;
    long long ans = 0;

    while (low <= high) {
        long long mid = (low + high) / 2;
        if (canAchieve(mid, power, r, k)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}
int main() {
    int r=1,k=2;
    vector<int> stations={1,2,3,4,5,6,7,8,9,10};
    cout<<maxPower(stations,r,k);
    
    return 0;
}