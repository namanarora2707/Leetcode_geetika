#include <bits/stdc++.h>
using namespace std;
int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
    int totalApples = 0;
    for (int a : apple) {
        totalApples += a;
    }

    sort(capacity.begin(), capacity.end(), greater<int>());

    int usedBoxes = 0;
    int currentCapacity = 0;

    for (int cap : capacity) {
        currentCapacity += cap;
        usedBoxes++;
        if (currentCapacity >= totalApples) {
            break;
        }
    }

    return usedBoxes;

}
int main() {
    vector<int> apple = {1, 2, 3, 4, 5};
    vector<int> capacity = {5, 4, 3, 2, 1};
    cout << minimumBoxes(apple, capacity) << endl;
    return 0;
}