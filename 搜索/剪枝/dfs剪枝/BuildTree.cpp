//
// Created by 自制力 on 2023/3/6.
//
#include <bits/stdc++.h>

using namespace std;
/*
 * N (0 ~ 10)
 * "01" string len 2^N
 */
int n;
char s[1024];

struct Node {
    char type;
    Node *leftChild;
    Node *rightChild;

    Node() {
        type = 'X';
        leftChild = rightChild = NULL;
    }

    Node(char c) {
        type = c;
        leftChild = rightChild = NULL;
    }
};

char check(char *str, int l, int r) {
    bool zeroTag = false, oneTag = false;
    for (int i = l; i < r; ++i) {
        if (str[i] == '0')
            zeroTag = true;
        if (str[i] == '1')
            oneTag = true;
        if (zeroTag && oneTag)
            return 'U';
    }
    return zeroTag ? 'F' : 'D';
}

Node *buildTree(char *str, int l, int r) {
    char rootType = check(str, l, r);
    Node *root = new Node(rootType);
    // 必须这样，二分时无法对 1 正确处理
    if (r - l == 1)
        return root;
    // 左闭右开，取上中位数的取法
    root->leftChild = buildTree(str, l, (l + r + 1) >> 1);
    root->rightChild = buildTree(str, (l + r + 1) >> 1, r);
    return root;
}

void postTraversal(Node *x) {
    if (x) {
        postTraversal(x->leftChild);
        postTraversal(x->rightChild);
        cout << x->type;
    }
}

int main() {
    scanf("%d", &n);
    scanf("%s", &s);
    Node *root = buildTree(s, 0, 1 << n);
    postTraversal(root);
    return 0;
}
