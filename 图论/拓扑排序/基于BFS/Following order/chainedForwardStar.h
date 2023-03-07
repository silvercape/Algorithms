//
// Created by 自制力 on 2023/3/7.
//

#ifndef README_MD_CHAINEDFORWARDSTAR_H
#define README_MD_CHAINEDFORWARDSTAR_H

#include <map>
#include <vector>

template<typename T>
class Edge {
public:
    T to;
    int next;
};

template<typename T>
class CFS {
public:
    std::vector<Edge<T>> edge;
    std::map<T, int> head;

    void addEdge(T from, T to) {
        Edge<T> newEdge = Edge<T>();
        newEdge.to = to;
        newEdge.next = head.find(from) == head.end() ?
                       -1 : head[from];
        head[from] = edge.size();
        edge.push_back(newEdge);
    }

};

#endif //README_MD_CHAINEDFORWARDSTAR_H
