//
// Created by 自制力 on 2023/2/6.
// 洛谷 P1996, STL list
// In
// 10 3
// Out
// 3 6 9 2 7 1 8 5 10 4

#include <bits/stdc++.h>

using namespace std;

int main() {
    // get people number and out number
    int n, m;
    cin >> n >> m;

    // stimulate
    list<int> l(n);
    int i = 1;
    for (auto it = l.begin(); it != l.end(); it++, i++) {
        *it = i;
    }
    i = 1;
    auto j = l.begin();
    while (!l.empty()) {
        if (i == m) {
            cout << *j << " ";
            auto j_next = next(j) == l.end() ? l.begin() :  next(j);
            l.erase(j);
            j = j_next;
            i = 1;
        } else {
            i = i + 1;
            j =  next(j) == l.end() ? l.begin() :  next(j);
        }
    }

    return 0;
}

