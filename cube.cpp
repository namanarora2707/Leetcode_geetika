#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main (){
    int m;
    cin>>m;

    vector <int>n(m);
    for(int i=0;i<m;i++){
        cin>>n[i];
    }
    
    sort(n.begin(),n.end());

    for(int i=0;i<m;i++){
        cout<<n[i]<<" ";
    }
    
    return 0;
}