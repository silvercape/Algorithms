//
// Created by 自制力 on 2023/2/14.
//
#include <bits/stdc++.h>
#include "SelfUfTry.h"

using namespace std;
int n;
const int MAXN = 1007;
int matrix[MAXN][MAXN];

class point {
public:
    int x;
    int y;

    point() {}

    ~point() {}

    point(int setX, int setY) {
        x = setX;
        y = setY;
    }

    bool operator==(point p) const {
        return (x == p.x) && (y == p.y);
    }

    bool operator!=(point p) const {
        return (this->x != p.x) || (this->y != p.y);
    }

    bool operator<(point p) const {
        if (x < p.x)
            return true;
        if (x == p.x)
            return y < p.y;
        return false;
    }

    int hashIndex() const {
        return (x << 10) + y;
    }
};

bool safe[MAXN][MAXN];

int main() {

    UF<point> uf;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf(" %c", &matrix[i][j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            bool isIsland[4] = {false};
            if (matrix[i][j] == '#') {
                if (i - 1 >= 0 && matrix[i - 1][j] == '#') {
                    isIsland[0] = true;
                }
                if (j - 1 >= 0 && matrix[i][j - 1] == '#') {
                    isIsland[1] = true;
                }
                if (i + 1 < n && matrix[i + 1][j] == '#') {
                    uf.Union({i, j}, {i + 1, j});
                    isIsland[2] = true;
                }
                if (j + 1 < n && matrix[i][j + 1] == '#') {
                    uf.Union({i, j}, {i, j + 1});
                    isIsland[3] = true;
                }
                if (isIsland[0] && isIsland[1] && isIsland[2] && isIsland[3]) {
                    /* point p =uf.f({i,j});
                     printf("Safe Set %d %d\n", p.x,p.y);
                     if(!safe[p.x][p.y])
                         cnt++;*/
                    safe[i][j] = true;
                    //printf("Safe Set %d %d\n", i,j);
                }
            }
        }
    }
    int allIsland = 0;
    int safeIsland = 0;
    set<point> s;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == '#') {
                point p = uf.FindSetIndex({i, j});
                //printf("%d %d f_set %d %d\n", i, j, p.x, p.y);
                if (p == point(i, j)) {
                    allIsland++;
                }
                if (safe[i][j]) {
                    s.insert(p);
                }
            }
        }
    }
    safeIsland = s.size();

    //cout << allIsland << endl;
    cout << allIsland - safeIsland << endl;
    return 0;
}