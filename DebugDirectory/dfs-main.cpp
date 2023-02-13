//
// Created by 自制力 on 2023/2/13.
//

#include <bits/stdc++.h>

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
};

class UfArray {
public:
    UfArray() {
        arr = new point[UfArray::MAXN][UfArray::MAXN];
        for (int i = 0; i < UfArray::MAXN; ++i) {
            for (int j = 0; j < UfArray::MAXN; ++j) {
                arr[i][j].x = i;
                arr[i][j].y = j;
            }
        }
    }

    ~UfArray() {
        delete arr;
    }

    point &operator[](point p) {
        return arr[p.x][p.y];
    }


private:
    static const int MAXN = 1007;
    point (*arr)[UfArray::MAXN];
};

// Quick Union
class UF {
public:
    UF() {};

    ~UF() {};

    // 需要避免成环
    void u(point p1, point p2) {
        p1 = f(p1);
        p2 = f(p2);
        ufArray[p2] = p1;
    }

    point f(point p) {
        return (p == ufArray[p]) ? p : f(ufArray[p]);
    }

private:
    UfArray ufArray;
};

bool safe[MAXN][MAXN];

int main() {
    UF unionFind = UF();
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
                if (i - 1 > 0 && matrix[i - 1][j] == '#') {
                    isIsland[0] = true;
                }
                if (j - 1 > 0 && matrix[i][j - 1] == '#') {
                    isIsland[1] = true;
                }
                if (i + 1 < n && matrix[i + 1][j] == '#') {
                    unionFind.u({i, j}, {i + 1, j});
                    isIsland[2] = true;
                }
                if (j + 1 < n && matrix[i][j + 1] == '#') {
                    unionFind.u({i, j}, {i, j + 1});
                    isIsland[3] = true;
                }
                if (isIsland[0] && isIsland[1] && isIsland[2] && isIsland[3]) {
                    /* point p =unionFind.f({i,j});
                     printf("Safe Set %d %d\n", p.x,p.y);
                     if(!safe[p.x][p.y])
                         cnt++;*/
                    safe[i][j] = true;
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
                point p = unionFind.f({i, j});
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