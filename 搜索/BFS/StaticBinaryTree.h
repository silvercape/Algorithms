//
// Created by 自制力 on 2023/2/13.
//

#ifndef README_MD_STATICBINARYTREE_H
#define README_MD_STATICBINARYTREE_H

#include <typeinfo>

typedef int Index;

template<typename T>
class Node {
public:
    Node() { value = 0; };

    ~Node() {};

    Node(T v) { value = v; }

    T value;
    Index lChild, rChild;

};

template<typename T>
class StaticBinaryTree {
public:
    StaticBinaryTree() {
        tree = new Node<T>[MAXN];
    }

    ~StaticBinaryTree() {
        delete tree;
    }

    Node<T> *tree;
    const int MAXN = 100005;
    Index last = 0;

    Index newNode(T v) {
        tree[last].value = v;
        tree[last].lChild = -1;
        tree[last].rChild = -1;
        return last++;
    }

    void insert(Index &father, Index child, bool insertAsLeftChild) {
        if (insertAsLeftChild) tree[father].lChild = child;
        else tree[father].rChild = child;
    }

    Node<T> operator[](Index index) {
        return tree[index];
    }

    Index buildTree() {


        Index A = newNode('A');
        Index B = newNode('B');
        Index C = newNode('C');
        Index D = newNode('D');
        Index E = newNode('E');
        Index F = newNode('F');
        Index G = newNode('G');
        Index H = newNode('H');
        Index I = newNode('I');
        insert(E, B, true);
        insert(E, G, false);
        insert(B, A, true);
        insert(B, D, false);
        insert(G, F, true);
        insert(G, I, false);
        insert(D, C, true);
        insert(I, H, true);
        Index root = E;
        return root;
    }
};


#endif //README_MD_STATICBINARYTREE_H
