//
// Created by 自制力 on 2023/2/13.
//

#ifndef README_MD_TRYUF_H
#define README_MD_TRYUF_H

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
        return x == p.x && y == p.y;
    }

    bool operator!=(point p) const {
        return (this->x != p.x) || (this->y != p.y);
    }
};

class UfArray {
public:
    UfArray() {
        cout << "UfArray Init" << endl;
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

    void u(point p1, point p2) {

        while (ufArray[p1] != p1) {
            p1 = ufArray[p1];
        }
        while(ufArray[p2]!=p2){
            p2=ufArray[p2];
        }

        ufArray[p2] = p1;
    }

    bool f(point p1, point p2) {
        point tmp1 = p1, tmp2 = p2;
        while (ufArray[tmp1] != tmp1) {
            tmp1 = ufArray[tmp1];
        }
        while (ufArray[tmp2] != tmp2) {
            tmp2 = ufArray[tmp2];
        }
        return tmp1 == tmp2;
    }

private:
    UfArray ufArray;
};



#endif //README_MD_TRYUF_H
