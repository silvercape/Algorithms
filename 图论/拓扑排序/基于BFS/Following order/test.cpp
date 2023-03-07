//
// Created by 自制力 on 2023/3/7.
//
#include "chainedForwardStar.h"
#include <iostream>
using namespace std;
int main() {
    auto cfs = CFS<char>();
    int n, m; cin>>n>>m;
    for (int i = 0; i < m; ++i) {
        char u, v;
        cin>>u>>v;
        cfs.addEdge(u, v);
    }
    for(int i = cfs.head['a']; i != -1; i = cfs.edge[i].next) {
        printf("%c\t", cfs.edge[i].to);
    }
    return 0;
}
