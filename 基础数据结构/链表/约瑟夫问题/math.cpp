//
// Created by 自制力 on 2023/2/6.
// 洛谷 P1996
// In
// 10 3
// Out
// 3 6 9 2 7 1 8 5 10 4

#include <bits/stdc++.h>

using namespace std;

int recur(int n, int m) {
    if (n == 1) {
        return 1;
    }
    // 最后位置直接取余会得到 0 ，为避免这种情况，先 -1 再 +1.
    return (recur(n - 1, m) + m - 1) % n + 1;

}

int main() {
    // get people number and out number
    int n, m;
    cin >> n >> m;

    cout << recur(n, m) << endl;
    return 0;
}

