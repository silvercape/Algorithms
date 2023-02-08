//
// Created by 自制力 on 2023/2/6.
//
/* 洛谷 P1540
 * 内存中 M 个单元，N 个单词，先来先走
 * InPut
 *  M N
 *  N 个非负整数，代表单词 hash(<=1000)
 * OutPut
 *  查询外存次数 K
 */
#include <bits/stdc++.h>

using namespace std;
int Hash[1003] = {0};
queue<int> q;

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    int cnt = 0;

    while (n--) {
        int en;
        scanf("%d", &en);
        if (!Hash[en]) {
            cnt += 1;
            Hash[en] = 1;
            q.push(en);
            if (q.size() > m) {
                Hash[q.front()] = 0;
                q.pop();
            }
        }
    }

    printf("%d\n", cnt);
    return 0;
}

