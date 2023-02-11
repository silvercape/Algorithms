#include<bits/stdc++.h>

using namespace std;
const int MAXN = 1e6 + 7;
int n, d, k;
int a[MAXN][2];
int dp[MAXN];
deque<int> dq;

bool check(int g) {
    memset(dp, -127, sizeof(dp));
    dq.clear();
    int l_b = d + g, r_b = max(d - g, 1), last = 0;
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        // rebuild [l,r]
        // build tail
        while (a[i][0] - a[last][0] >= r_b) {
            // only reachable
            if (dp[last] > -99999999) {
                // in queue
                while (!dq.empty() && dp[dq.back()] <= dp[last]) {
                    dq.pop_back();
                }
                dq.push_back(last);
            }
            last++;
        }
        // build head
        while (!dq.empty() && a[i][0] - a[dq.front()][0] > l_b) {
            dq.pop_front();
        }
        if (!dq.empty()) {
            dp[i] = dp[dq.front()] + a[i][1];
        }
        if (dp[i] >= k) {
            return true;
        }
    }
    return false;
}

int main() {
    scanf("%d %d %d", &n, &d, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", &a[i][0], &a[i][1]);
    }

    int l = 0, r = a[n - 1][0];
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else
            l = mid + 1;
    }
    int ans = l == a[n - 1][0] ? -1 : l;
    printf("%d", ans);
    return 0;
}