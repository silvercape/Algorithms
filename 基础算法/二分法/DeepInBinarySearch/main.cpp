//
// Created by 自制力 on 2023/2/12.
//
#include <bits/stdc++.h>
using namespace std;
/*
 * 向下取整 [l, r) mid = (l+r)/2 [0,1) mid 在 0 处更接近左边，就是向下取整
 */
/*
 * int lower_bound(int *arr, int len, int tar) {
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

 */
// the one less and last
int lowerBoundMinus(int* arr,int len, int tar) {
    int l=0,r=len;
    while(l<r){
        int mid=(l+r)>>1;
        /*
         * 每次移动right 只在arr[mid]>=tar
         * 保证所有大的在right右边
         * 每次移动left 只在arr[mid]<tar
         * 保证所有小的在left左边
         * [right --> 大于等于
         * )left --> 小于
         * [ ) 最后一个元素
         * l r
         * 若大于等于
         * [) r-- l==r==大于等于第一个 且后面都大于等于
         * left-1 is wanted
         * 若小于
         *   [) l++ l==r==大于等于第一个
         * 若不存在 l==r==n
         *
         */
        if(arr[mid]>=tar){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    return l-1;

}

int upperBound(int* arr, int len, int tar){
    /*  = must in left or right and cannot both
     *  and must one ] one ( or when l==r this no answer.
     *  for simple l r is to be [l,r)
     * ]left <=
     * (right >
     * [ )  the last value
     * l r
     * mid must be <= because of l==mid
     * then l++
     *    [)
     *    lr
     * l==r and loop end, but we can't judge the last l is what
     * Undefined
     * the last value must be l and if l is assumed to contain =
     * then can't work
     * so l --- ) and r --- [
     * and this two pairs
     *   left) <=   right[ >    ---> upperBound
     *   left) <    right[ >=   ---> lowerBound
     *   for instance1
     *   [  )
     *   l  r
     *   if <=
     *   left++
     *      [)
     *      lr
     *   l==r==the first >
     *   if >
     *   r--
     *   [)
     *   lr
     *   l==r==the first >
     */
    int _left=0, _right=len;
    while(_left<_right){
        int _mid=(_left+_right)>>1;
        if (arr[_mid] <= tar)
            _left = _mid+1;
        else
            _right=_mid;
    }
    return _left;
}
/*
 * = 单独拿出来说
 * )left <= (right>  Undefined
 * )left <  (right>= Undefined
 * )left < [right >
 *  if last < tar
 *      l++
 *      l==r==第一个大于
 *  if last==tar
 *      break
 *  if last>tar
 *      r--
 *      l==r==第一个大于
 */

/*
 * 由于 left 必须对应 ) left=mid+1
 * 每次移动left分两种 < 或 <=
 * 无论哪种，left左边一定是满足<或<=
 * 同样每次移动right] right=mid
 * right一定对应>或者>=
 * 而且最后left和right一定会相遇，按照我们的模板写法，即收敛于upper或lower
 * 满足比较条件的ans的考察区间，枚举一定完全，可以边二分边保存结果。
 * /2 向下取整 left=mid+1 right=mid
 * left+right+1 /2 向上取整 right=mid-1 left=mid
 * 向上取整
 * [  )
 * l  r
 * 比的是r
 * 要求 r ( l]
 * 对应两组
 * r( >  l] <=  最后一个小于等于 x 的数  a a a x x x [x] b b b
 * r( >= l] <   最后一个小于    x 的数  a a [a] x x x x b b b
 */
/*
 * 如果用 [l,r]
 * 则 )l  (r  >= 和 <= 可随意分配
 * 最后一定是 []
 *          lr
 * 这时必须l++或r--与取整方式无关
 * 循环结束时 l>r但没有用
 * 要知道最后一次结果必须分开判断
 * 举个例子
 * if <= update ans
 *  最后ans的位置就是最后一个<=的位置
 *  <  同理
 *  > >= 第一个的位置
 *  但注意初始化ans的值，若未匹配需要给ans正确的初始值
 */

int lower_bound(int *arr, int len, int tar) {
    int l = 0, r = len;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (arr[mid] >= tar)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}


int lower_bound_version_2(int *arr, int len, int tar) {
    int l = 0, r = len-1;
    int ans=len;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (arr[mid] >= tar) {
            ans=mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return ans;
}

int upper_bound(int* arr, int len, int tar) {
    int _left=0, _right=len;
    while(_left<_right){
        int _mid=(_left+_right)>>1;
        if (arr[_mid] <= tar)
            _left = _mid+1;
        else
            _right=_mid;
    }
    return _left;
}
int main(){
    int testArray[]={1,1,2,3,3,4,4,4,5,5,6,6,6,7,7,7};
    printf("lower minus find %d at %d\n", 5, lowerBoundMinus(testArray,16,15));
    printf("lower  find %d at %d\n", 5, lower_bound(testArray,16,15));
    printf("lower  2  find %d at %d\n", 5, lower_bound_version_2(testArray,16,15));

    return 0;
}
