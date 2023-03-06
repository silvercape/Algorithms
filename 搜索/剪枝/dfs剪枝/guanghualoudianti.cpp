//
// Created by 自制力 on 2023/2/15.
//
#include <bits/stdc++.h>

using namespace std;

/*
 * n 层电梯 n<100
 * 从 a 到 b
 * 返回最短步数
 *  从 k 可加可减 d[k]
 */

int n, s, e;
int d[207];
int vis[207];
/*
 * dep 可以起到代替 visited 的作用
 * 并且可用于剪枝
 */

/*
 *      0------------
 *      |     |     |
 *  ----1     |     |
 *  |   |     |     |
 *  |   2-----|     |
 *  |   |           |
 *  |---3------------
 *  这种情况 dfs 非常慢
 *  最坏情况指数级
 */

void dfs(int cur, int dep) {
    // 剪枝
    // 其一，避免回路
    // 其二，保留最短路径
    if (vis[cur] != -1 && vis[cur] <= dep) {
        return;
    }
    vis[cur] = dep;
    int upLevel = cur + d[cur];
    int downLevel = cur - d[cur];
    if (upLevel <= n) {
        dfs(upLevel, dep + 1);
    }
    if (downLevel > 0) {
        dfs(downLevel, dep + 1);
    }
}

int main() {
    cin >> n >> s >> e;
    for (int i = 1; i <= n; ++i) {
        cin >> d[i];
    }
    memset(vis, -1, sizeof(vis));
    dfs(s, 0);
    printf("%d", vis[e]);
    return 0;
}