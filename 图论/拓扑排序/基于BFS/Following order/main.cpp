//
// Created by 自制力 on 2023/3/7.
//
#include <bits/stdc++.h>

using namespace std;
const int N = 10007;
// 默认边数是点数的两倍
struct Edge {
    int to;
    int next;
} edge[2 * N];
int cnt = 0, cntNode, head[N], node[N], inDegree[N];

void addEdge(int u, int v) {
    cnt++;
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt;
}

// 都映射到大于 1 的位置，0表示空
int hashC2I(char c) {
    return c - 'a' + 1;
}
// 逆映射
char hashI2C(int i) {
    return i + 'a' - 1;
}

int main() {
    string s;
    while (getline(cin, s)) {
        cntNode = 0;
        memset(inDegree, 0, sizeof(inDegree));
        for_each(s.begin(), s.end(),
                 [&](char c) {
                     if (isalpha(c))
                         node[cntNode++] = hashC2I(c);
                 });
        // sort(node, node + cntNode);
        getline(cin, s);
        bool first = true;
        int st, ed;
        for_each(s.begin(), s.end(),
                 [&](char c) {
                     if (first && isalpha(c)) {
                         st = hashC2I(c);
                         first = false;
                     } else if ((!first) && isalpha(c)){
                         ed = hashC2I(c);
                         inDegree[ed]++;
                         addEdge(st, ed);
                         first = true;
                     }
                 });
        cout << cntNode << endl;

        priority_queue<int, vector<int>,greater<int >> priorityQueue;
        for (int i = 0; i < cntNode; ++i) {
            if(inDegree[node[i]] == 0) {
                priorityQueue.push(node[i]);
            } else {
            }
        }
        while(!priorityQueue.empty()) {
            int cur = priorityQueue.top();
            printf("%c", hashI2C(cur));
            priorityQueue.pop();
            for(int i=head[cur];i!=0;i=edge[i].next){
                int to = edge[i].to;
                inDegree[to]--;
                if (inDegree[to] == 0) {
                    priorityQueue.push(to);
                }
            }
        }
    }


    return 0;
}
