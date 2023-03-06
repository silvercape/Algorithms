//
// Created by 自制力 on 2023/3/6.
//
/*
 * Input:
 * n C
 * w_i c_i m_i
 * 价值 体积 数量
 */
#include <bits/stdc++.h>

using namespace std;
const int N = 100010;
int n, C, w[N], c[N], m[N], dp[2][N];

int main() {
    cin >> n >> C;
    for (int i = 1; i <= n; i++) cin >> w[i] >> c[i] >> m[i];
    int now = 0, old = 1;
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        swap(now, old);
        for (int j = 1; j <= C; j++) {
            for (int k = 0; k <= m[i] && k * c[i] <= j; k++) {
                dp[now][j] = max(dp[now][j], dp[old][j - k * c[i]] + k * w[i]);
            }
        }
    }
    cout << dp[now][C] << endl;
    return 0;
}