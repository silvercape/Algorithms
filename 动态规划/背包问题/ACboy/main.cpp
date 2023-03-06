//
// Created by 自制力 on 2023/3/6.
//
#include <bits/stdc++.h>

using namespace std;
/*
 * 可建模为分组背包
 * 每个组内最多有一个可以装进背包，所以需要组内遍历选一个
 */
const int N = 105;
int n, m, dp[N], w[N][N], c[N][N];

int main() {
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin >> w[i][j];
                c[i][j] = j;
            }
        }
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; ++i) {
            for (int j = m; j > 0; --j) {
                for (int k = 1; k <= m; ++k) {
                    if (j >= c[i][k]) {
                        dp[j] = max(dp[j], dp[j - c[i][k]] + w[i][k]);
                    }
                }
            }
        }
        printf("%d\n", dp[m]);
    }
    return 0;
}
