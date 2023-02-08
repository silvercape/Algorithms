//
// Created by 自制力 on 2023/2/8.
//
/*
 * 单调队列：
 * 单调递减，队头最大，为当前队列最大值
 * 单调递增，队头最小，为当前队列最小值
 * 去尾：保持单调性
 * 删头：保持窗口特性
 * InPut：
 *  n (队伍人数) k (窗口大小)
 *  n 个整数
 * OutPut：
 *  n - k + 1 个数，窗口最小值
 *  n - k + 1 个数，窗口最大值
 */
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7;
int a[N];
deque<int> q;


int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    /*
     * 队内信息
     *
     * q 内存下标比较好，q 内存的数据内容是当前窗口的最值
     * 但是窗口左右下标需要额外内存
     * 右下标固定为 i
     * 左下标为 i + 1 - k(窗口完整时，也是从 i+1-k>=0 开始输出)
     * 去尾是每次加新队友时执行
     * 删头是每次窗口右移时*队列头元素*恰好是*窗口左下标对应元素*时删去
     * 删头判断时需要判断头元素对应下标，而下标好找内容，内容不好找下标
     * 存下标，两个信息都能保持
     */
    /*
     * 判断条件
     *
     * 去尾判断(min)：
     *  单调增，来了一个，必须入队(窗口移动到后面不会有前面的信息)
     *  前面比它大的全离去
     * 删头判断(min)：
     *  先看窗口满了吗，满了之后
     *  队列头 deque.front() < i+1-k 删头
     */
    for (int i = 0; i < n; i++) {
        // 去尾
        while (!q.empty() && a[q.back()] >= a[i]) {
            q.pop_back();
        }
        // 入队
        q.push_back(i);

        if (i + 1 - k >= 0) {
            // 去头
            if (q.front() < i + 1 - k) {
                q.pop_front();
            }
            // 输出最小值
            printf("%d ", a[q.front()]);
        }
    }
    printf("\n");
    /*
     * 为何删头也可以用 while 也可以用 if
     *
     *  每次入队后，至多删一次头
     */
    q.clear();
    for (int i = 0; i < n; i++) {
        // 去尾
        while (!q.empty() && a[q.back()] <= a[i]) {
            q.pop_back();
        }
        // 入队
        q.push_back(i);

        if (i + 1 - k >= 0) {
            // 去头
            if (q.front() < i + 1 - k) {
                q.pop_front();
            }
            // 输出最大值
            printf("%d ", a[q.front()]);
        }
    }
    return 0;
}