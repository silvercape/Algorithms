# Following orders
## 问题描述
按照字母序输出字典序最小的拓扑排序
## 输入
每个测试两行，第 1 行是字母，第 2 行是字母的关系
一对字母 x y 表示 x < y。
字母数量 2~20，字母对数量 <= 50
## 输出
对每个测试，按字母序输出所有的拓扑排序

##输入样例
a b f g

a b b f

##输出样例
abfg


## 解释
a b
b f
表示图

a -- > b --> f

g
输出 abfg
