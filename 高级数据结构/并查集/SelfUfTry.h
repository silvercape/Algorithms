//
// Created by 自制力 on 2023/2/14.
//
#ifndef README_MD_SELF_UF_TRY_H
#define README_MD_SELF_UF_TRY_H

template<class E>
class UF;

template<class E>
class MapForUnionFind;

/*
 * 返回元素
 * 要求元素重载 <
 * 要求元素有 hashIndex() 函数
 */
template<class E>
class UF {
public:
    E FindSetIndex(E e) {
        if (!m.find(e))
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
        return FindSetIndex(e1) == FindSetIndex(e2);
    }

private:
    MapForUnionFind<E> m;
};


/*
 * 辅助类 MapForUnionFind
 * 要求元素值对应内存不能为全为-1
 */
template<class E>
class MapForUnionFind {
public:
    MapForUnionFind() {
        hash = new E[N];
        memset(hash, -1, N * sizeof(E));
    }

    ~MapForUnionFind() { delete hash; }

    // 需要在外部修改，所以把内部hash[e]返回出去引用
    E &operator[](E ele) { return hash[ele.hashIndex()]; };

    // 判断是否已经有该key
    bool find(E ele) {
        char *begin = (char *) &hash[ele.hashIndex()];
        for (int i = 0; i < sizeof(ele); ++i, ++begin)
            if (~(*begin))
                return true;
        return false;
    }

private:
    const int N = 1000005;
    E *hash;
};


#endif //README_MD_SELF_UF_TRY_H