//
// Created by 自制力 on 2023/3/7.
//
#include<bits/stdc++.h>

using namespace std;

int n, m;
const int N = 5007;

struct Edge {
    int from, to, w;

    bool operator<(struct Edge edge) const {
        return w < edge.w;
    }
} e[200007];

int uf[N];

void initUf() {
    for (int i = 1; i <= n; ++i) {
        uf[i] = i;
    }
}

int find_set(int x) {
    while (uf[x] != x)
        x = uf[x];
    return x;
}

void U(int u, int v) {
    int u_set = find_set(u);
    int v_set = find_set(v);
    uf[v_set] = u_set;
}

int main() {
    cin >> n >> m;
    // 其实并查集直接当成双向边了
    for (int i = 1; i <= m; ++i) {
        cin >> e[i].from >> e[i].to >> e[i].w;
    }
    sort(e + 1, e + m + 1);
    initUf();
    int ans = 0, cnt = 0;
    for (int i = 1; i <= m; ++i) {
        if (cnt == n - 1)
            break;
        int u_set = find_set(e[i].from);
        int v_set = find_set(e[i].to);
        if (u_set != v_set) {
            uf[v_set] = u_set;
            ans += e[i].w;
            cnt++;
        }
    }
    if (cnt == n - 1)
        cout << ans;
    else
        cout << "orz";
    return 0;
}
