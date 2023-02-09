//
// Created by 自制力 on 2023/2/9.
//
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 7;
int x[MAXN];
int s[MAXN];
int n, d, k;

// 二分 + dp优化 == O(n lgn)
// level 4

int main() {

    scanf("%d %d %d", &n, &d, &k);

    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &x[i], &s[i]);
    }



    return 0;
}
