//
// Created by 自制力 on 2023/3/7.
//
#include<bits/stdc++.h>

using namespace std;


/*
 * 采用邻接表
 */
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int N = 3e5 + 2;
int n, m;
long long dis[N];
bool vis[N];
/*
 * 同时可以得到最短路径生成树
 * 只需在更新某个点的最短路径时，
 * 保存其前面的from
 * 最后更新的反正一定是最短路径树的一部分
 *
 * 方法一如果要输出最短路径树需要额外保存from信息
 * 方法二直接保存即可
 * 本文只在方法二进行输出
 */
int pre[N];

struct edge {
    int from, to, w;

    edge(int from, int to, int weight) : from(from), to(to), w(weight) {}
};

vector<edge> e[N];

void debug();

void dijkstra(int st) {
    for (int i = 1; i <= n; ++i) {
        dis[i] = INF;
    }
    // use priority_queue
    /*
     * 存什么？ 结点或者边(for print_path)
     * 按什么比较？ 结点到source的距离
     * 故需要 {
     *  int node_number;
     *  long long weight_to_source;
     * }
     * 大根还是小根堆？
     * 距离越短优先级越高
     * 距离大的优先级低
     * if dis_a > dis_b
     *  p_a < p_b
     *  return true
     * 返回true则a的优先级<b的优先级
     */
    struct Node {
        int from;
        int n_id;
        long long dis_to_src;

        Node(int id, long long w) : n_id(id), dis_to_src(w) {}

        Node(int from, int id, long long w) : from(from), n_id(id), dis_to_src(w) {}

        //注意声明函数为const，否则编译不会通过,表示我们不会修改成员变量的值
        bool operator<(Node node) const {
            if (dis_to_src > node.dis_to_src)
                return true;
            return false;
        }
    };
    priority_queue<Node> q;
    q.push(Node(st, 0));
    /*
     * 到达某个点可能更近，可能更远
     * 更远理论上舍弃不更新
     * 更近理论上需要更新
     * 但是我们简单处理，由于只取最近的，
     * 即重复的只有最近的第一个取出
     * 这时我们标记一下，已经是最近了
     * 之后遇到的丢弃，
     * 其实更新更好，但是不能做到。
     *
     *  修正：
     *      方法二
     *      在入队时进行更新
     */
    srand(time(NULL));
    int choice = rand() % 2 + 1;
    cout << "Method[" << choice << "]" << endl;
    if (choice == 1) {
        // 方法一 出队更新，一定最短，后面的不管，queue保存距离，dis存最终结果
        while (!q.empty()) {
            Node cur = q.top();
            q.pop();
            if (vis[cur.n_id])
                continue;
            vis[cur.n_id] = true;
            pre[cur.n_id] = cur.from;
            dis[cur.n_id] = cur.dis_to_src;
            // printf("update node %d dis %d\n", cur.node_number, cur.weight_to_source);
            for (auto item: e[cur.n_id]) {
                if (!vis[item.to]) {
                    // printf("add node %d and dis %d\n", item.to, item.w + cur.weight_to_source);
                    q.push(Node(item.from, item.to, item.w + cur.dis_to_src));
                }
            }
        }
    } else if (choice == 2) {
        // 方法二,入队时更新，dis表示距离，queue与dis不同步
        dis[st] = 0;
        while (!q.empty()) {
            Node cur = q.top();
            q.pop();
            /*
             * 如果是非最短路径的结点到达这里
             * 一定是vis过的，所以不用比对dis
             * 直接用vis把它筛掉
             */
            if (vis[cur.n_id])
                continue;
            vis[cur.n_id] = true;
            for (auto item: e[cur.n_id]) {
                // 这时我们更新，同时减少入队，相比于方法一更优
                if (!vis[item.to] && dis[item.to] > item.w + cur.dis_to_src) {
                    pre[item.to] = item.from;
                    dis[item.to] = item.w + cur.dis_to_src;
                    q.push(Node(item.to, item.w + cur.dis_to_src));
                }
            }
        }
    }

/*
         * 打印最短路径树
         * 每个结点逆序打印即可
         */
    cout << "<=Path:" << endl;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j != st; j = pre[j]) {
            printf("%d<=", j);
        }
        cout << st << endl;
    }
    auto printPath = [&](auto &&self, int i) {
        if (i == st) {
            cout << i;
            return;
        }
        self(self, pre[i]);
        cout << "=>" << i;
    };
    /*
     * 运用递归可以使箭头逆向
     */
    cout << "=>Path:" << endl;
    for (int i = 1; i <= n; ++i) {
        printPath(printPath, i);
        cout << endl;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        e[i].clear();
    }
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].emplace_back(u, v, w);
    }
    debug();
    dijkstra(1);
    for (int i = 1; i <= n; ++i) {
        if (dis[i] == INF)
            cout << -1 << " ";
        else
            cout << dis[i] << " ";
    }
    cout << endl;
    return 0;
}


void debug() {
    for (int i = 1; i <= n; ++i) {
        cout << "node[" << i << "]:" << endl;
        for_each(e[i].begin(), e[i].end(), [](edge e) {
            printf("\tfrom:[%d] to:[%d] weight[%d]\n", e.from, e.to, e.w);
        });
    }
}