//
// Created by 自制力 on 2023/2/9.
//
/*
 * 模拟题，使用链表即可
 */
/*
 * InPut:
 *  N 1<M≤N≤100000
 *  N行2N个数，每行 k p
 *  p = 0 i 插入 k 左边
 *  p = 1 i 插入 k 右边
 *  第一个直接插
 *  第N+1行M删除M个学生
 *  M行每行一个x，删除x号学生，若x不在忽略
 */
#include <bits/stdc++.h>

using namespace std;
list<pair<int, bool>> l;
const int MAXN = 1e5 + 7;

using Iter = list<pair<int, bool>>::iterator;
Iter pos[MAXN];

int main() {
    int n;
    cin >> n;
    l.insert(l.begin(), make_pair(1, true));
    pos[1] = l.begin();
    for (int i = 2; i <= n; ++i) {
        int k, p;
        cin >> k >> p;

        /*
         * 过去的找位置代码
         * auto iter = l.begin();
         * while(*iter != k)
            iter++;
         * 超时间
         * 用哈希表记录位置
         */
        auto iter = pos[k];

        if (p == 1) {
            iter++;
        }
        pos[i] = l.insert(iter, make_pair(i, true));
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;

        /*
         * 过去的删除代码
         *  l.remove(x);
         * 超时，多存储一个tag记录是否需要打印
         * tag == ture print
         * tag == false not print
         */

        (*pos[x]).second = false;
    }
    for (auto iter = l.begin(); iter != l.end(); iter++) {
        if ((*iter).second)
            cout << (*iter).first << " ";
    }
    return 0;
}