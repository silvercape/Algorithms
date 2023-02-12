//
// Created by 自制力 on 2023/2/12.
//

#include <bits/stdc++.h>
#include "MinHeap.hpp"

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int op;
    MinHeap heap = MinHeap();
    while (n--) {
        scanf("%d", &op);
        int k;
        switch (op) {
            case 1:
                scanf("%d", &k);
                heap.push(k);
                break;
            case 2:
                printf("%d\n", heap.top());
                break;
            case 3:
                heap.pop();
                break;
        }
    }
    return 0;
}