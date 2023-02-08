//
// Created by 自制力 on 2023/2/8.
//
/*
 * https://leetcode-cn.com/problems/maximum-subarray/
 * InPut:
 *  T 测试用例个数
 *  T行，每行 N（整数） + N 个数
 *  1 <= N <= 100000
 *  每个数在 [-1000, 1000]
 * OutPut:
 *  每个测试两行共 2T 行
 *  第一行 Case #: (#代表序号)
 *  第二行 三个数： 最大子序列和 左下标 右下标
 *  加一个空行
 */
#include <bits/stdc++.h>

using namespace std;

const int INF = 0x7fffffff;
/*
 * 其实贪心算法就是动态规划算法，只不过优化了
 */
int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        int n;
        scanf("%d", &n);
        int maxsum = -INF;
        int start = 0, end = 0, p = 0;
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            int a;
            scanf("%d", &a);
            sum += a;
            if (maxsum < sum) {
                maxsum=sum;
                start=p;
                end=j;
            }
            if(sum<0){
                sum=0;
                p=j+1;
            }
        }
        printf("Case %d:\n", i);
        printf("%d %d %d\n", maxsum, start, end);
        if (i != T)
            printf("\n");
    }
    return 0;
}