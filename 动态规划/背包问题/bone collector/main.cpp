//
// Created by 自制力 on 2023/3/6.
//
#include <bits/stdc++.h>

using namespace std;
/*
 * 测试用例个数
 * T
 * N C
 * w_i 价值
 * c_i 体积
 */
/*
 * dp 为 N+1 * C+1
 */
const int N = 1011;
int T, n, C;
int w[N], c[N], dp[N][N];

int solve(int i, int j) {
    if (dp[i][j] != 0)
        return dp[i][j];
    if (i == 0) return 0;
    int ans = solve(i - 1, j);
    if (c[i] <= j)
        ans = max(ans, solve(i - 1, j - c[i]) + w[i]);
    dp[i][j] = ans;
    return dp[i][j];
}

int topDown(int n, int C) {
    memset(dp, 0, sizeof(dp));
    return solve(n, C);
}

int bottomUp(int n, int C) {
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= C; j++) {
            if (c[i] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - c[i]] + w[i]);
            }
        }
    }
    return dp[n][C];
}

int main() {
    cin >> T;
    while (T--) {
        cin >> n >> C;
        for (int i = 1; i <= n; i++) cin >> w[i];
        for (int i = 1; i <= n; i++) cin >> c[i];
        cout << topDown(n, C) << endl;
        cout << bottomUp(n, C) << endl;
    }
    return 0;
}
