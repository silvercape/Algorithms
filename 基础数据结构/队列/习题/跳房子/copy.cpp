#include<bits/stdc++.h>

using namespace std;
long long n, d, k, f[500005], a[500005][2], q[500005], l = 0, r = 100005;

bool check(int g) {
    memset(f, -127, sizeof(f));
    memset(q, 0, sizeof(q));
    long long x = max(d - g, (long long) 1), s = d + g;
    long long head = 1, tail = 0, j = 0;
    f[0] = 0;
    //依次转移每个i
    for (long long i = 1; i <= n; i++) {
        //决策候选集合
        while (a[i][0] - a[j][0] >= x && j < i) {
            if (f[j] > -99999999) {
                //检查队尾单调性
                while (f[q[tail]] <= f[j] && head <= tail)tail--;
                q[++tail] = j;//符合单调性后，插入决策j
            }
            j++;
        }
        //检查队头是否过时
        while (a[i][0] - a[q[head]][0] > s && head <= tail)head++;
        if (head <= tail)f[i] = f[q[head]] + a[i][1];//实行决策
        if (f[i] >= k)return true;
    }
    return false;
}

int main() {
    cin >> n >> d >> k;
    for (long long i = 1; i <= n; i++)cin >> a[i][0] >> a[i][1];
    //二分判定花费mid个金币是否可行
    while (l < r) {
        long long mid = l + r >> 1;
        if (check(mid))r = mid;
        else l = mid + 1;
    }
    if (l == 100005)cout << -1;
    else cout << l;
    return 0;
}