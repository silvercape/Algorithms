//
// Created by 自制力 on 2023/2/15.
//
#include <bits/stdc++.h>

using namespace std;
const int N = 1010;
char mp[N][N];
bool vis[N][N];
int d[4][2] = {
        {0,  1},
        {0,  -1},
        {1,  0},
        {-1, 0}
};

bool bfs(int x, int y) {
    bool hasHighLand = false;
    queue<pair<int, int>> q;
    // 不能重复入队，在入队前访问
    // 二叉树层序遍历之所以可以后遍历，因为边只是单向边
    vis[x][y]=1;
    q.push({x, y});
    while (!q.empty()) {
        pair<int, int> t = q.front();
        q.pop();
        int tx = t.first, ty = t.second;
        //vis[tx][ty] = true;
        if (mp[tx][ty + 1] == '#' && mp[tx][ty - 1] == '#' &&
            mp[tx + 1][ty] == '#' && mp[tx - 1][ty] == '#')
            hasHighLand = true;
        for (int i = 0; i < 4; ++i) {
            int nx = tx + d[i][0], ny = ty + d[i][1];
            if (vis[nx][ny]==0 && mp[nx][ny] == '#') {
                vis[nx][ny]=1;
                q.push({nx, ny});
            }
        }
    }
    return hasHighLand;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> mp[i];
    int ans=0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mp[i][j] == '#' && !vis[i][j])
                if (!bfs(i, j))
                    ans++;
        }
    }
    cout << ans << endl;
    return 0;
}