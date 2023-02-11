//
// Created by 自制力 on 2023/2/11.
//
/*
 * InPut
 *  N T
 *  N 个数据（有序有重复）
 * OutPut
 *  第一个大于等于的下标，若无，返回 N
 */
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e7 + 5;
int a[MAXN];

int lower_bound(int *arr, int len, int tar) {
    int l = 0, r = len - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (arr[mid] >= tar)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

int upper_bound(int* arr, int len, int tar) {
    int _left=0, _right=len-1;
    while(_left<_right){
        int _mid=(_left+_right)>>1;
        if (arr[_mid] <= tar)
            _left = _mid+1;
        else
            _right=_mid;
    }
    return _left;
}

int main() {
    int n, t;
    scanf("%d %d", &n, &t);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    int ret = lower_bound(a, n, t);
    printf("target:%d lower_bound find at pos %d\n", t, ret);
    ret = upper_bound(a,n,t);
    printf("target:%d upper_bound find at pos %d\n", t, ret);
    return 0;
}
