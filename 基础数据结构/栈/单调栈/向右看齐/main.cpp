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
 *  R_1 ~ R_n（从下标1开始而非0）
 *
 * 输入规模提示我们使用 O(n lgn)的算法
 */
/*
 * 初步分析
 *  仔细观察可发现，这不属于区间最值问题，而是最近最值问题
 *  经过思考，使用区间阶梯型性质可以解决最近最值问题
 *
 * 具体思路
 *  使用单调栈维护每个奶牛位置右边的区间内的奶牛高度信息
 *  使其呈阶梯状，即从左往右看的左视图
 *  找到第一个比该奶牛高的即为所求
 *
 * 代码思路
 *  存储下标还是具体数（身高）
 *      同队列，存下标
 *  如何遍历
 *      因为是维护每个位置i右边的区间，即[i+1:n-1]的阶梯信息
 *      所以从后往前扩大区间合适，从后向前遍历
 *  如何维护单调栈性质（阶梯性质）
 *      此问题应该维护上升阶梯性质
 *      使用性质
 *          每次新奶牛向右看，[i+1:n-1]的区间内为上升阶梯
 *          找到第一个比自己高的，就是该奶牛的仰望对象
 *      维护性质
 *          奶牛i入队，区间为[i:n-1]
 *          要维护信息使得其意义为从奶牛i-1向右看的阶梯
 *          那么显然把奶牛i和其仰望对象之间的奶牛出队即可
 *          (显然看不到)
 *      【注】可以看到在维护区间性质时分为入队和维护性质两步
 *          具体即入队和出队，都发生在队头，故类似栈，只在一边出入
 *          记为单调栈
 */
#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e6 + 7;
int a[MAXN];
int upCows[MAXN];
stack<int> s;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = n - 1; i >= 0; --i) {
        // 使用性质，找到仰望对象，同时可以维护性质（一边找一边出栈）
        while (!s.empty() && a[s.top()] <= a[i]) {
            s.pop();
        }
        // 此时栈若不空，栈顶即为仰望对象，否则为0
        int upCow = s.empty() ? 0 : s.top();
        //题目下标从1开始，我们需要+1
        upCows[i] = upCow ? upCow + 1 : upCow;
        // 入队，前面已经出队了，区间阶梯性质得到维护
        s.push(i);
    }

    for (int i = 0; i < n; ++i) {
        cout << upCows[i];
        if (i != n - 1)
            cout << endl;
    }

    return 0;
}
