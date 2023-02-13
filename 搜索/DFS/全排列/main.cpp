//
// Created by 自制力 on 2023/2/13.
//

#include <bits/stdc++.h>

using namespace std;

const int range = 3;
int arr[range];
int used[1000];
vector<int>ans;

void dfs(int n) {
    if (n == 0) {
        for(auto v: ans)
            cout<<v<<" ";
        printf("\n");
        return;
    }
    for(int i=0;i<range;i++){
        if(used[i]==0){
            ans.push_back(arr[i]);
            used[i]=1;
            dfs(n-1);
            used[i]=0;
            ans.pop_back();
        }
    }
}

int main() {
    srand(time(NULL));
    for (int i = 0; i < range; ++i) {
        arr[i] = rand() % 100 + 1;
    }
    for (int i = 0; i < range; ++i) {
        printf("%4d\t", arr[i]);
    }
    printf("\n");
    printf("All Sort:\n");
    dfs(range);

    return 0;
}