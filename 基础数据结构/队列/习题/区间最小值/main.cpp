//
// Created by 自制力 on 2023/2/9.
//

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e7 + 5;
deque<int> dq;
int a[MAXN];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    // 起始条件 [x:i-1]
    // 先入后出
    for (int i = 0; i < n; ++i) {
        // 直接使用性质，注意边界
        int minV = dq.empty() ? 0 : a[dq.front()];
        printf("%d", minV);
        if (i != n - 1)
            printf("\n");

        // 最小值，递减，入队时找比它小的
        while (!dq.empty() && a[dq.back()] >= a[i])
            dq.pop_back();
        dq.push_back(i);

        // 维护区间
        if (dq.front() < i + 1 - m)
            dq.pop_front();

    }

    return 0;
}