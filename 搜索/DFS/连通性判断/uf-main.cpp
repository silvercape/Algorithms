//
// Created by 自制力 on 2023/2/13.
//

#include <bits/stdc++.h>

using namespace std;
int n;
const int MAXN = 1007;
int matrix[MAXN][MAXN];

struct point {
    int x;
    int y;

    bool operator==(point &p) {
        return x == p.x && y == p.y;
    }

    bool operator!=(point &p) {
        return x != p.x || y != p.y;
    }
};

point uf[MAXN][MAXN];

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
    UF() {
        uf = UfArray();
    }

    ~UF() {};

    void u(point p1, point p2) {
        point tmp = p1;
        while (uf[tmp] != tmp) {
            tmp = uf[tmp];
        }
        uf[tmp] = p2;
    }

    bool f(point p1, point p2) {
        point tmp1 = p1, tmp2 = p2;
        while (uf[tmp1] != tmp1) {
            tmp1 = uf[tmp1];
        }
        while (uf[tmp2] != tmp2) {
            tmp2 = uf[tmp2];
        }
        return tmp1 == tmp2;
    }

private:
    UfArray uf;
};


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
                    unionFind.u({i, j}, {i - 1, j});
                    isIsland[0] = true;
                }
                if (j - 1 > 0 && matrix[i][j - 1] == '#') {
                    unionFind.u({i, j}, {i, j - 1});
                    isIsland[1] = true;
                }
                if (i + 1 < n && matrix[i + 1][j] == '#') {
                    unionFind.u({i, j}, {i + 1, j});
                    isIsland[2]= true;
                }
                if (j + 1 < n && matrix[i][j + 1] == '#') {
                    unionFind.u({i, j}, {i, j + 1});
                    isIsland[3]= true;
                }
            }
        }
    }
    printf("Has Been Union: matrix[%d][%d] matrix[%d][%d] %d",
           1,1,2,2,unionFind.f({1,1},{2,2}));
    return 0;
}