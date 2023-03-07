//
// Created by 自制力 on 2023/3/7.
//
#include <bits/stdc++.h>

using namespace std;
const int N = 405;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;
int n, m, q;
long long dp[N][N];

int main() {
    cin >> n >> m >> q;
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= n; ++i) {
        dp[i][i] = 0;
    }
    for (int i = 1; i <= m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        // 防止重边
        dp[u][v] = dp[v][u] = min(dp[u][v], w);
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    int s, t;
    while(q--) {
        cin>>s>>t;
        if(dp[s][t] == INF)
            cout<<-1<<endl;
        else
            cout<<dp[s][t]<<endl;
    }
    return 0;
}
