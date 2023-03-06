//
// Created by 自制力 on 2023/3/6.
//
#include <bits/stdc++.h>

using namespace std;
const int N = 500005;
int fa[N], head[N], cnt, head_query[N], cnt_query, ans[N];
bool vis[N];
struct Edge {
    int to, next, num;
} edge[2 * N], query[2 * N];

void init() {
    for (int i = 0; i < 2 * N; ++i) {
        edge[i].next = -1;
        head[i] = -1;
        query[i].next = -1;
        head_query[i] = -1;
    }
    cnt = cnt_query = 0;
}

void addEdge(int u, int v) {
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

void addQuery(int x, int y, int num) {
    query[cnt_query].to = y;
    query[cnt_query].num = num;
    query[cnt_query].next = head_query[x];
    head_query[x] = cnt_query++;
}

int findSet(int x) {
    return fa[x] == x ? x : findSet(fa[x]);
}

void tarjan(int x) {
    vis[x] = true;
    for (int i = head[x]; i != -1; i = edge[i].next) {
        int y = edge[i].to;
        if (!vis[y]) {
            tarjan(y);
            fa[y] = x;
        }
    }
    for (int i = head_query[x]; i != -1; i = query[i].next) {
        int y = query[i].to;
        if (vis[y])
            ans[query[i].num] = findSet(y);
    }
}

int main() {
    init();
    memset(vis, 0, sizeof(vis));
    int n, m, root;
    scanf("%d %d %d", &n, &m, &root);
    for (int i = 1; i < n; ++i) {
        fa[i] = i;
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }
    fa[n] = n;
    for (int i = 1; i <= m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        addQuery(a, b, i);
        addQuery(b, a, i);
    }
    tarjan(root);
    for (int i = 1; i <= m; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
