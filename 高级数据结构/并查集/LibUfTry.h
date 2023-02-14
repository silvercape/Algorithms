//
// Created by 自制力 on 2023/2/14.
//
#ifndef README_MD_LIB_UF_TRY_H
#define README_MD_LIB_UF_TRY_H

#include <map>

template<class E>
class UF;

/*
 * 库 map
 * 需要 #include<map>
 * 需要元素重载 <
 * 自动初始化
 */
template<class E>
class UF {
public:
    E FindSetIndex(E e) {
        if (m.find(e) == m.end())
            m[e] = e;
        while (m[e] < e || e < m[e])
            e = m[e];
        return e;
    }

    void Union(E e1, E e2) {
        e1 = FindSetIndex(e1);
        e2 = FindSetIndex(e2);
        m[e2] = e1;
    }

    bool Find(E e1, E e2) {
        e1 = FindSetIndex(e1);
        e2 = FindSetIndex(e2);
        return !(e1 < e2 || e2 < e1);
    }

private:
    std::map<E, E> m;
};

#endif //README_MD_LIB_UF_TRY_H