所谓并查集，关键在于如何在两个给定元素上建立并关系，以及查找这种关系

makeRelation 合并两个元素所在集合
checkRelation 查找两个元素是否在一个集合内

以整数上的并查集为例，建立整数上的并关系，记录信息在relation里
那么建立1和2之间的联系使用 makeRelation(1,2)
查找1和2之间的联系使用 checkRelation(1,2)
relation是一个集合，初始时每个整数属于不同集合，合并关系时把两个集合合并于一个集合
那么显然relation是大集合，里面包含所有元素，每个元素都是一个小集合


那么问题变为高效设计集合 ==> 答案是使用 map
map[元素]给出所属集合信息，可以是整数，也可以是元素，可唯一标识集合
具体合并和查找策略分为以下两种(具体思路参考算法第四版)
quick-union
    元素所属集合标号是集合根部 root 的map[root]，即root的初始集合标号
    特征 除root外，其他元素x 的 map[x] != 所属集合标号
quick-find
    元素所属集合标号相同

那么问题来到如何设计 map
    ? map[?]
    接受参数显然是元素合适, 如何使得用元素本身做索引呢？
        map 库
        自己实现
            实现元素到下标的映射(0,1,2,...)
    返回参数呢？或者说如何设计元素标号呢？
    是元素本身还是元素的哈希值？（请先确保理解了quick-union和quick-find)

使用map库时，显然元素本身比较方便，因为返回哈希值还需要设计哈希映射
但自己实现时，下标索引本身就是元素的哈希映射，所以返回哈希值方便。
下面分别尝试一下
给定元素 point{
    int x;
    int y;
}
注意，类似于整数，我们把内容一样的元素直接当成相同，如果考虑内存中位置，
应自己设置 == 判断，库map读取<，也注意设置<判断，用指针而非内容。
1. map 库函数
    需要重载 point 的 < 运算符 const 是map的要求
    bool operator<(point p) const {
        return x == p.x ? y < p.y : x < p.x;
    }
    初始化
    map<point, point> m;
    for each element e:
        map[e] = e;
    quick-union
    辅助函数
    point FindSetIndex(point p){
        while(!(hash[p] == p))
            p=hash[p];
        return p;
    }
    void Union(point p1, point p2){
        p1=FindSetIndex(p1);
        p2=FindSetIndex(p2);
        hash[p2]=p1;
    }
    bool Find(point p1, point p2){
        return FindSetIndex(p1)==FindSetIndex(p2);
    }
2. 自己实现
    下标哈希
    2.1 返回元素
        相当于自己实现map,由于map内存储元素，不能预先初始化
        所以动态初始化，自己实现find函数。我这边简单实现。
        需要元素对应内存不能全为-1.
        point类需要重载 operator==，添加hashIndex()函数

    2.2 返回哈希值
        更简单，不需要辅助类，直接用数组
        具体要求见头文件。