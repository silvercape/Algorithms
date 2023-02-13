//
// Created by 自制力 on 2023/2/13.
//

#include <bits/stdc++.h>
#include "StaticBinaryTree.h"
using namespace std;

int main(){
    StaticBinaryTree<char> staticBinaryTree;
    int root=staticBinaryTree.buildTree();
    queue<int>q;
    q.push(root);
    while(q.size()){
        int tmp=q.front();
        cout<<staticBinaryTree[tmp].value<<" ";
        q.pop();
        if(staticBinaryTree[tmp].lChild!=-1)q.push(staticBinaryTree[tmp].lChild);
        if(staticBinaryTree[tmp].rChild!=-1)q.push(staticBinaryTree[tmp].rChild);
    }
    return 0;
}