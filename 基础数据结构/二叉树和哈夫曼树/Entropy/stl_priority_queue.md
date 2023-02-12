优先队列
优先队列是一种抽象数据类型（Abstract Date Type,ADT），行为和队列类似，但是先出队的元素不是先进队列的元素，而是队列中优先级最高的元素。
STL的优先队列定义在头文件<queue>和 （队列一样），用"priority_queue< int >pq"来声明；
最基本的用法

      定义：priority_queue<int>pq；

      操作：
                pq.empty() 如果队列为空返回真

                pq.pop() 删除对顶元素

                pq.push() 加入一个元素

                pq.size() 返回优先队列中拥有的元素个数

                pq.top() 返回优先队列对顶元素
下面我们介绍几种优先队列的定义方式：

      priority_queue<int>pq 默认的是整数越大，优先级越高，如果想让他 整数越小 优先级越高怎么办？
      STL中也有模板   “priority_queue<int,vector<int>,greater<int > >pq”
      上面的尖括号内第一个 参数为入队元素类型（int），第二个为容器类型（vector<int>），第三个为比较函数（greater<int>）
      因此我们也能自定义
           priority_queue<int,vector<int>,cmp1 >pq; 最小值优先
           priority_queue<int,vector<int>,cmp2 >pq2; 最大值优先

```c++
struct cmp1{  
    bool operator ()(int &a,int &b){  
        return a>b;//最小值优先  
    }  
};  
struct cmp2{  
    bool operator ()(int &a,int &b){  
        return a<b;//最大值优先  
    }  
};  
```
