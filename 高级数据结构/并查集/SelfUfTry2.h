//
// Created by 自制力 on 2023/2/14.
//
#ifndef README_MD_SELF_UF_TRY_2_H
#define README_MD_SELF_UF_TRY_2_H

template<class E>class UF;

/*
 * 返回哈希值
 * 要求元素有 hashIndex() 函数
 */
template<class E>
class UF {
public:
    UF() {
        m = new int[N];
        for (int i = 0; i < N; ++i)
            m[i] = i;
    }

    ~UF() { delete m; }

    int FindSetIndex(E e) {
        int i = e.hashIndex();
        while (i != m[i]) {
            i = m[i];
        }
        return i;
    }

    void Union(E e1, E e2) {
        int i = FindSetIndex(e1);
        int j = FindSetIndex(e2);
        m[j] = i;
    }

    bool Find(E e1, E e2) {
        return FindSetIndex(e1) == FindSetIndex(e2);
    }

private:
    const int N = 1000005;
    int *m;
};


#endif //README_MD_SELF_UF_TRY_2_H
