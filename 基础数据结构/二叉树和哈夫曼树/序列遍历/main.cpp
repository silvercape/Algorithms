//
// Created by 自制力 on 2023/2/14.
//
#include<bits/stdc++.h>

using namespace std;

class Node {
public:
    int value;
    Node *leftChild;
    Node *rightChild;
    Node *father;

    Node() {
        value = 0;
        leftChild = rightChild = father = NULL;
    }

    Node(int setV) {
        value = setV;
        leftChild = rightChild = father = NULL;
    }

};

void setLF(Node *l, Node *f) {
    if (l) l->father = f;
    if (f) f->leftChild = l;
}

void setRF(Node *r, Node *f) {
    if (r) r->father = f;
    if (f) f->rightChild = r;
}

Node *buildTree() {
    Node *root = new Node(9);
    setLF(new Node(4), root);
    setRF(new Node(5), root);
    setRF(new Node(11), root->leftChild);
    setLF(new Node(7), root->rightChild);
    setRF(new Node(1), root->rightChild);
    setRF(new Node(12), root->rightChild->leftChild);
    /*
     *        9
     *    4       5
     *      11  7   1
     *           12
     */
    return root;
}

// give the first node in post in one tree or a subtree
Node *headNodeInPostTraversal(Node *root) {
    Node *head = root;
    while (head && head->leftChild != NULL || head->rightChild != NULL) {
        if (head->leftChild)
            head = head->leftChild;
        else
            head = head->rightChild;
    }
    return head;
}

// give the first node in pre
Node *headNodeInPreTraversal(Node *root) {
    return root;
}

// give the first node in mid
Node *headNodeInMidTraversal(Node *root) {
    Node *head = root;
    while (head && head->leftChild)
        head = head->leftChild;
    return head;
}

// Non-Null l r x
Node *successNodeInPostTraversal(Node *root) {
    // Only return No deep in
    if (root->father == NULL)
        return NULL;
    // Is left son
    if (root == root->father->leftChild)
        if (root->father->rightChild)
            return headNodeInPostTraversal(root->father->rightChild);

    // Is right son
    return root->father;
}

// Non-Null x l r
Node *successNodeInPreTraversal(Node *root) {
    // deep in first find l then find r
    if (root->leftChild)
        return headNodeInPreTraversal(root->leftChild);
    if (root->rightChild)
        return headNodeInPreTraversal(root->rightChild);
    // return
    while (root->father) {
        // Is left child find r
        if (root->father->leftChild == root)
            if (root->father->rightChild)
                return root->father->rightChild;
        // l r done, l r's fa return.
        root = root->father;
    }
    // tree root
    return NULL;
}

// Non-Null l x r
Node *successNodeInMidTraversal(Node *root) {
    // deep in find r
    if (root->rightChild)
        return headNodeInMidTraversal(root->rightChild);
    // return
    while (root->father) {
        // Is left return x(fa)
        if (root->father->leftChild == root)
            return root->father;
        // Is right for fa, l r done, fa return
        root = root->father;
    }
    // tree root
    return NULL;
}

void postTraversalNonRecursion(Node *root) {
    Node *head = headNodeInPostTraversal(root);

    while (head) {
        printf("%d ", head->value);
        head = successNodeInPostTraversal(head);
    }
}

void preTraversalNonRecursion(Node *root) {
    Node *head = headNodeInPreTraversal(root);

    while (head) {
        printf("%d ", head->value);
        head = successNodeInPreTraversal(head);
    }
}

void midTraversalNonRecursion(Node *root) {
    Node *head = headNodeInMidTraversal(root);

    while (head) {
        printf("%d ", head->value);
        head = successNodeInMidTraversal(head);
    }
}

void postTraversalRecursion(Node *root) {
    if (root) {
        postTraversalRecursion(root->leftChild);
        postTraversalRecursion(root->rightChild);
        printf("%d ", root->value);
    }
}

void midTraversalRecursion(Node *root) {
    if (root) {
        midTraversalRecursion(root->leftChild);
        printf("%d ", root->value);
        midTraversalRecursion(root->rightChild);
    }
}

void preTraversalRecursion(Node *root) {
    if (root) {
        printf("%d ", root->value);
        preTraversalRecursion(root->leftChild);
        preTraversalRecursion(root->rightChild);
    }
}


int main() {
    Node *root = buildTree();
    postTraversalRecursion(root);
    printf("\n");
    postTraversalNonRecursion(root);
    printf("\n");
    preTraversalRecursion(root);
    printf("\n");
    preTraversalNonRecursion(root);
    printf("\n");
    midTraversalRecursion(root);
    printf("\n");
    midTraversalNonRecursion(root);
    return 0;
}
