//
// Created by 自制力 on 2023/2/14.
//
#include <bits/stdc++.h>
//#include "SelfUfTry.h"
#include "SelfUfTry2.h"

using namespace std;

// x < 1000 and y < 1000
// rows = 1024
class point {
public:
    int x;
    int y;

    bool operator<(point p) const {
        return x == p.x ? y < p.y : x < p.x;
    }

    int hashIndex() { return (x << 10) + y; }

    bool operator==(point p) { return p.x == x && p.y == y; }
};

// Use for init and test.
point ps[10];
UF<point> uf;

void initUF() {
    for (int i = 0; i < 10; ++i) {
        ps[i].x = rand() % 100 + 1;
        ps[i].y = rand() % 100 + 1;
        printf("point[%d] (%d, %d)\n", i, ps[i].x, ps[i].y);
    }

    printf("Init finish.\n");
}

void testUF() {
    auto pf = [=](int a, int b) {
        printf("Find(ps[%d], ps[%d]):%d\n", a, b, uf.Find(ps[a], ps[b]));
    };
    uf.Union(ps[0], ps[1]);
    pf(0,2);
    uf.Union(ps[2], ps[9]);
    uf.Union(ps[4], ps[3]);
    uf.Union(ps[5], ps[9]);
    pf(0, 1);
    pf(0, 2);
    uf.Union(ps[1], ps[5]);
    pf(0,2);
}


int main() {

    initUF();
    testUF();
    return 0;
}