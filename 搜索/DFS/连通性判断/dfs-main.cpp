//
// Created by 自制力 on 2023/2/15.
//
#include <bits/stdc++.h>

using namespace std;
const int N = 1010;
char mp[N][N];
bool vis[N][N];
int d[4][2] = {{0,  1},
               {0,  -1},
               {1,  0},
               {-1, 0}};

bool dfs(int x, int y) {
    vis[x][y] = 1;
    bool hasHighLand = false;
    if (mp[x][y + 1] == '#' && mp[x][y - 1] == '#' &&
        mp[x + 1][y] == '#' && mp[x - 1][y] == '#')
        hasHighLand = 1;
    for (int i = 0; i < 4; ++i) {
        int nx = x + d[i][0], ny = y + d[i][1];
        if (!vis[nx][ny] && mp[nx][ny] == '#')
            hasHighLand |= dfs(nx, ny);
    }
    return hasHighLand;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> mp[i];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mp[i][j] == '#' && vis[i][j] == 0) {
                if (!dfs(i, j)) ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}