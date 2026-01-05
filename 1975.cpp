#include <bits/stdc++.h>
using namespace std;
long long maxMatrixSum(vector<vector<int>>& matrix) {
    long long sum = 0;
    int negativeCount = 0;
    int minAbs = INT_MAX;

    for (auto &row : matrix) {
        for (int x : row) {
            if (x < 0) negativeCount++;
            sum += abs(x);
            minAbs = min(minAbs, abs(x));
        }
    }
    if (negativeCount % 2 == 1) {
        sum -= 2LL * minAbs;
    }

    return sum;
}
int main() {
    vector<vector<int>> matrix = {{1, -2, 3}, {-4, 5, -6}, {7, -8, 9}};
    cout << maxMatrixSum(matrix) << endl;
    return 0;
}