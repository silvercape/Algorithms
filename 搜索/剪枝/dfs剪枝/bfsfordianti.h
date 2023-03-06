//
// Created by 自制力 on 2023/3/6.
//

#ifndef README_MD_BFSFORDIANTI_H
#define README_MD_BFSFORDIANTI_H

#include <queue>
#include <string.h>

using std::queue;

template<typename T>
class Queue : public queue<T> {
public:
    T pop() {
        T ret = queue<T>::front();
        queue<T>::pop();
        return ret;
    }
};

int bfs(int n, int s, int *d) {
    Queue<int> q;
    int vis[207];
    q.push(s);
    memset(vis, -1, sizeof(vis));
    vis[s] = 0;
    while (!q.empty()) {
        int cur = q.pop();
        int upLevel = cur + d[cur];
        int downLevel = cur - d[cur];
        if (upLevel <= n && vis[upLevel] == -1) {
            vis[upLevel] = vis[cur] + 1;
            q.push(upLevel);
        }
        if (downLevel > 0 && vis[downLevel] == -1) {
            vis[downLevel] = vis[cur] + 1;
            q.push(downLevel);
        }
    }
}

#endif //README_MD_BFSFORDIANTI_H
