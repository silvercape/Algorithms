//
// Created by 自制力 on 2023/2/9.
//
/*
 * N 头牛，身高 H_n ，找每头牛右边第一头比它高的牛的位置R_n，没有输出 0
 *
 * InPut：
 *  N  (1 <= N <= 100000)
 *  H_1 ~ H_n (1 <= H_i <= 1000000)
 * OutPut：
 *  R_1 ~ R_n
 *
 * 输入规模提示我们使用 O(n lgn)的算法，我们这次先使用 O(n^2) 果然超时
 */
#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e6 + 7;
int a[MAXN];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        int tmp = a[i];
        a[i] = 0;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] > tmp) {
                a[i] = j + 1;
                break;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i];
        if (i != n - 1)
            cout << endl;
    }
    return 0;
}
