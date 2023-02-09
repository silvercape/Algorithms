//
// Created by 自制力 on 2023/2/9.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        while (true) {
            string s;
            cin >> s;
            reverse(s.begin(), s.end());
            cout << s << " ";
            char ch = getchar();
            if (ch == '\n' || ch == EOF)
                break;
        }
        cout << endl;
    }
    return 0;
}