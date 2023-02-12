//
// Created by 自制力 on 2023/2/12.
//

#ifndef README_MD_MINHEAP_HPP
#define README_MD_MINHEAP_HPP


class MinHeap {
public:
    MinHeap();
    ~MinHeap();

    void push(int x);
    void pop();
    int top();
    int size();
    bool empty();

private:
    const int MAXN=1e6+5;
    int *heap;
    int tail=0;
};


#endif //README_MD_MINHEAP_HPP
