//
// Created by 自制力 on 2023/2/12.
//
// #include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

// 最大值优先
priority_queue<int, vector<int>, greater<int>> q;
string s;
int cnt[256];

int main() {
    while (getline(cin, s) && s != "END") {
        memset(cnt, 0, sizeof(cnt));
        for(string::iterator iter=s.begin();iter!=s.end();iter++)
            cnt[*iter]++;

        for (int i = 0; i < 256; ++i)
            if (cnt[i])
                q.push(cnt[i]);

        int ans = 0;
        if (q.size() == 1)
            ans = s.length();
        while (q.size() > 1) {
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            q.push(a + b);
            ans += a + b;
        }
        q.pop();
        printf("%d %d %.1f\n",
               s.length() * 8,
               ans,
               (double) s.length() * 8 / (double) ans
        );
    }
    return 0;
}
