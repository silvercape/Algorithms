//
// Created by 自制力 on 2023/3/6.
//

#include <bits/stdc++.h>

using namespace std;
/*
 * 输入的边附带权值
 *  n s e
 *  d[n]
 *  n 行
 *  priceDown priceUp
 */
int n, s, e;
int d[207];
int price[207][2];
int vis[207];

void dfs(int cur, int curPrice) {
    if (vis[cur] != -1 && vis[cur] < curPrice)
        return;
    vis[cur] = curPrice;
    int downStair = cur - d[cur];
    int upStair = cur + d[cur];
    if (downStair >= 1) {
        dfs(downStair, curPrice + price[cur][0]);
    }
    if (upStair <= n) {
        dfs(upStair, curPrice + price[cur][1]);
    }
}

int main() {
    cin >> n >> s >> e;
    for (int i = 1; i <= n; ++i)
        scanf("%d", &d[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%d %d", &price[i][0], &price[i][1]);
    memset(vis, -1, sizeof(vis));

    dfs(s, 0);
    for (int i = 1; i <= n; ++i) {
        printf("%d ", vis[i]);
    }
    return 0;
}