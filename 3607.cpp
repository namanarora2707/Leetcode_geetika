#include <bits/stdc++.h>
using namespace std;
struct DSU {
    vector<int> parent, size;
    vector<set<int>> onlineStations;

    DSU(int n) {
        parent.resize(n+1);
        size.assign(n+1, 1);
        onlineStations.resize(n+1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            onlineStations[i].insert(i); 
        }
    }

    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        if (onlineStations[b].size() > onlineStations[a].size())
            swap(onlineStations[a], onlineStations[b]);
        onlineStations[a].insert(onlineStations[b].begin(), onlineStations[b].end());
        onlineStations[b].clear();
    }
};
vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
    DSU dsu(c);

    for (auto &edge : connections) {
        dsu.unite(edge[0], edge[1]);
    }

    vector<int> res;
    vector<bool> online(c+1, true);

    for (auto &q : queries) {
        int type = q[0], x = q[1];
        int root = dsu.find(x);

        if (type == 1) {
            if (online[x]) res.push_back(x);
            else {
                if (dsu.onlineStations[root].empty()) res.push_back(-1);
                else res.push_back(*dsu.onlineStations[root].begin());
            }
        } else if (type == 2) {
            if (online[x]) {
                online[x] = false;
                dsu.onlineStations[root].erase(x);
            }
        }
    }
    return res;
}
int main() {
    int c=5;
    vector<vector<int>> connections={{1,2},{2,3},{3,4},{4,5}};
    vector<vector<int>> queries={{1,1},{2,1},{1,2},{2,3},{1,4},{2,5}};
    vector<int> res=processQueries(c,connections,queries);
    for(auto i:res)cout<<i<<" ";
    return 0;
}