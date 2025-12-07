#include <bits/stdc++.h>
using namespace std;
int countOdds(int low, int high) {
    int cnt=0;
    for(int i=low;i<=high;i++){
        if(i%2==1){
            cnt++;
        }
    }
    return cnt;
}
int main() {
    int low, high;
    cin >> low >> high;
    cout << countOdds(low, high) << endl;
    return 0;
}