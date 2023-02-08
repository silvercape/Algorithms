//
// Created by 自制力 on 2023/2/8.
//
/*
 * 此处限制子序列长度不超过 m，
 * 即找出一段长度不超过 m 的子序列和最大
 * InPut:
 *  T (测试用例个数)
 *  n m n个数，子序列长度 m
 *  n 个数
 * Output
 *  Case #:
 *  k 最大和
 */
/*
 * 使用前缀和
 * preSum[i] = sum[0:i) = sum[0:i-1]
 *  preSum[0] = 0
 *  preSum[i] = preSum[i-1] + arr[i-1]
 *
 *  sum[i:j] = preSum[j+1] - preSum[i]
 * 对每个 j 找前面最小的 preSum[i]
 * 即在固定 j 时，计算区间[j+1-m:j]上preSum的最小值
 * 计算差值再统一比较取最大值，因此用单调队列维护区间最值信息
 * 下面确定 j 的范围
 * 对每个 j 找以 j 结尾的最大子数组值
 * 即固定 preSum[j+1] 找前面的 preSum[i]
 * j in [0, n-1]
 */
#include<bits/stdc++.h>

using namespace std;

deque<int> dq;
int preSum[10005] = {0};
const int INF_MIN = 0x80000000;

void show(int a) {
    cout << a << " ";
}

int main() {
    int T;
    cin >> T;
    for (int k = 0; k < T; ++k) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            cin >> preSum[i];
        }
        for (int i = 1; i <= n; ++i) {
            preSum[i] += preSum[i - 1];
        }
        int ans = INF_MIN;
        for (int i = 0; i < n; ++i) {
            // 去尾
            while(!dq.empty() && preSum[dq.back()] >= preSum[i]){
                dq.pop_back();
            }
            // 入队
            dq.push_back(i);
            // 删头
            if (dq.front() < i + 1 -m) {
                dq.pop_front();
            }
            // 完成入队操作后，
            // 队列状态更新为新区间，计算 i 对应的 Max sum
            // 队头为最小的preSum
            ans = max(ans, preSum[i+1] - preSum[dq.front()]);
        }
        printf("Case %d:\n%d\n", k + 1, ans);
        if (k != T - 1)
            printf("\n");
    }

    return 0;
}
