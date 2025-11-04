#include <bits/stdc++.h>
using namespace std;
int minCost(string colors, vector<int>& neededTime) {
    int totalTime = 0;
    int n = colors.size();
    
    for (int i = 1; i < n; ++i) {
        if (colors[i] == colors[i - 1]) {
            totalTime += min(neededTime[i], neededTime[i - 1]);
            neededTime[i] = max(neededTime[i], neededTime[i - 1]);
        }
    }
    return totalTime;
}
int main() {
    string colors="aabac"
    vector<int> neededTime={1,2,3,4,5}
    cout<<minCost(colors, neededTime);
    return 0;
}