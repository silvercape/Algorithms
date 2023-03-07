//
// Created by 自制力 on 2023/3/7.
//
// #include<bits/stdc++.h>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
/*
 * 显然这里面点的个数有限
 * 且都处于相邻范围内
 * 故邻接矩阵为上解
 */
int n, a[30], dir[30][30];
int topo[30], vis[30], inDegree[30];

/*
 * 其实得到topo排序的原理就是不断找零入度结点
 * 删去，然后得到新的零入度结点。
 * 每一步可删去的零入度结点很多种可能
 * 因此形成了一棵选择树
 * dfs遍历整棵树，为防止回退，vis来记录当前路径上使用过的结点。
 */
void dfs(int st, int cnt) {
    topo[cnt] = st;
    if (cnt == n - 1) {
        for (int i = 0; i < n; ++i) {
            printf("%c", topo[i] + 'a');
        }
        cout << endl;
        return;
    }
    vis[st] = 1;
    // 删除结点
    for (int i = 0; i < n; ++i) {
        if (!vis[a[i]] && dir[st][a[i]])
            inDegree[a[i]]--;
    }
    // 挑选下一个dfs的选择。不确定种可能
    for (int i = 0; i < n; ++i) {
        if (!inDegree[a[i]] && !vis[a[i]])
            dfs(a[i], cnt + 1);
    }
    // 恢复，凡是回溯，必须恢复
    for (int i = 0; i < n; ++i) {
        if (!vis[a[i]] && dir[st][a[i]])
            inDegree[a[i]]++;
    }
    vis[st] = 0;
}

/*
 * 由于先对结点进行排序
 * dfs每次都优先找小的
 * 最后结果为字典序
 */
int main() {
    string s;
    while (getline(cin, s)) {
        memset(dir, 0, sizeof(dir));
        memset(vis, 0, sizeof(vis));
        memset(inDegree, 0, sizeof(inDegree));
        n = 0;
        for (auto c: s) {
            if (isalpha(c)) {
                a[n++] = c - 'a';
            }
        }

        sort(a, a + n);

        getline(cin, s);
        bool first = true;
        int st, ed;
        for (auto c: s) {
            if (isalpha(c)) {
                if (first) {
                    st = c - 'a';
                    first = false;
                } else {
                    ed = c - 'a';
                    first = true;
                    dir[st][ed] = 1;
                    inDegree[ed]++;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (inDegree[a[i]] == 0)
                dfs(a[i], 0);
        }
        cout << endl;
    }
    return 0;
}
