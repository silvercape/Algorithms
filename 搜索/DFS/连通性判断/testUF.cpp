//
// Created by 自制力 on 2023/2/14.
//

#include "SelfUfTry.h"
#include <bits/stdc++.h>
using namespace std;

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

int main(){
    UF<point> uf;
    uf.FindSetIndex({1,1});
    return 0;
}