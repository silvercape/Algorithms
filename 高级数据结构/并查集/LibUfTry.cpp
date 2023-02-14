//
// Created by 自制力 on 2023/2/14.
//

#include<bits/stdc++.h>

using namespace std;

class point {
public:
    int x;
    int y;

    bool operator<(point p) const {
        return x == p.x ? y < p.y : x < p.x;
    }

    bool operator==(point p) {
        return x == p.x && y == p.y;
    }

};

map<point, point> m;

point FindSetIndex(point p) {
    while (!(m[p] == p))
        p = m[p];
    return p;
}

void Union(point p1, point p2) {
    p1 = FindSetIndex(p1);
    p2 = FindSetIndex(p2);
    m[p2] = p1;
}

bool Find(point p1, point p2) {
    return FindSetIndex(p1) == FindSetIndex(p2);
}

// Use for init and test.
point ps[10];

void initLibUF() {
    for (int i = 0; i < 10; ++i) {
        ps[i].x = rand() % 100 + 1;
        ps[i].y = rand() % 100 + 1;
        printf("point[%d] (%d, %d)\n", i, ps[i].x, ps[i].y);
    }
    for (int i = 0; i < 10; ++i) {
        m[ps[i]] = ps[i];
    }
    printf("Init finish.\n");
}

void testLibUF(){
    Union(ps[0],ps[1]);
    Union(ps[2],ps[9]);
    Union(ps[4],ps[3]);
    Union(ps[5],ps[9]);
    cout<<Find(ps[0],ps[1])<<endl;
    cout<<Find(ps[0], ps[2])<<endl;
    Union(ps[1],ps[5]);
    cout<<Find(ps[0], ps[2])<<endl;
}

int main() {
    initLibUF();
    testLibUF();
    return 0;
}