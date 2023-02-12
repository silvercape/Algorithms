//
// Created by 自制力 on 2023/2/12.
//

#include<bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int,vector<int>, greater<int>> priorityQueue;
    int n; cin>>n;
    while(n--){
        int op; cin>>op;
        if(op==1) {int x; cin>>x; priorityQueue.push(x);}
        else if(op==2) cout<<priorityQueue.top()<<endl;
        else priorityQueue.pop();
    }
    return 0;
}