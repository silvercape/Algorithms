//
// Created by 自制力 on 2023/3/7.
//
#include<bits/stdc++.h>

using namespace std;
int n, m;
const int N = 5007;
const int M = 2e5 + 1;

/*
 * 存储图用邻接表方便获取邻接边
 * 存不存 from都行，加上不错
 */
struct Edge {
    int from, to, w;

    Edge(int from, int to, int w) : from(from), to(to), w(w) {}
};

vector<Edge> e[M];

// dis just the edge length
struct Node {
    int id, dis;

    Node(int id, int dis) : id(id), dis(dis) {}

    bool operator<(Node node) const {
        return dis > node.dis;
    }
};

bool done[N];

void prim(int st) {
    memset(done, 0, sizeof(done));
    priority_queue<Node> q;
    q.push(Node(1, 0));
    int ans = 0, cnt = 0;
    while (!q.empty()) {
        Node cur = q.top();
        q.pop();
        if (done[cur.id])
            continue;
        done[cur.id] = true;
        ans += cur.dis;
        cnt++;
        for (auto edge: e[cur.id]) {
            if (!done[edge.to]) {
                q.push(Node(edge.to, edge.w));
            }
        }
    }
    if (cnt == n)cout << ans;
    else cout << "orz";
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].emplace_back(u, v, w);
    }
    // 随便选。反正最小生成树只要有，每个点一定在。
    prim(1);
    return 0;
}
