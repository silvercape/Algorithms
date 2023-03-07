//
// Created by 自制力 on 2023/3/7.
//
#include<bits/stdc++.h>

using namespace std;
const int INF = 1e6;
const int N = 105;
struct Edge {
    int u, v, w;
} e[10005];
int n, m, cnt;
int pre[N];//记录前驱结点，用于打印路径
void print_path(int st, int cur) {
    if (st == cur) {
        cout << st;
        return;
    }
    print_path(st, pre[cur]);
    cout << "=>" << cur;
}

int dis[N];

void bellman(int st) {
    for (int i = 1; i <= n; i++)
        dis[i] = INF;
    dis[st] = 0;
    for (int k = 1; k <= n; k++) {
        for (int i = 0; i < cnt; i++) {
            int x = e[i].u, y = e[i].v;
            if (e[i].w + dis[x] < dis[y]) {
                dis[y] = e[i].w + dis[x];
                pre[y] = x;
            }
        }
    }
}

int main() {
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        cnt = 0; // 边的数量
        while (m--) {
            int st, ed, we;
            cin >> st >> ed >> we;
            // 单向边
            e[cnt].u = st;
            e[cnt].v = ed;
            e[cnt].w = we;
            cnt++;
        }
        for (int i = 0; i < cnt; ++i) {
            printf("edge[%d]: from[%d] to[%d] weight[%d]\n", i + 1, e[i].u, e[i].v, e[i].w);
        }
        bellman(1);
        printf("from %d to %d : dis %d\n", 1, n, dis[n]);
        for (int i = 1; i <= n; ++i) {
            if(dis[i] != INF) {
                print_path(1, i);
                cout << endl;
            }
        }
    }
    return 0;
}
