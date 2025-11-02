#include <bits/stdc++.h>
using namespace std;
int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
    vector<vector<int>> grid(m, vector<int>(n, 0));

    for (auto &g : guards) grid[g[0]][g[1]] = 2;
    for (auto &w : walls) grid[w[0]][w[1]] = 1;


    vector<pair<int,int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    
    for (auto &g : guards) {
        int r = g[0], c = g[1];
        for (auto &d : dirs) {
            int x = r + d.first, y = c + d.second;
            while (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] != 1 && grid[x][y] != 2) {
                if (grid[x][y] == 0)
                    grid[x][y] = 3; 
                x += d.first;
                y += d.second;
            }
        }
    }

    int unguarded = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0)
                unguarded++;
        }
    }

    return unguarded;
}
int main() {
    int m=4,n=6;
    vector<vector<int>> guards = {{0,0},{1,1},{2,3}};
    vector<vector<int>> walls = {{0,1},{2,2},{1,4}};
    cout << countUnguarded(m, n, guards, walls) << endl;

    return 0;
}