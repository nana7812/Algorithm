//
// Created by 김정음 on 2021/01/21.
//
#include <iostream>
using namespace std;

int n;
bool check[6];


int dfs(int x){
    if(x >= n){
        return 1;
    }

    for(int i = 1; i <= n; i++){
        if(check[i] == false) {
            check[i] = true;
            total += dfs(x+1);
            check[i] = false;
        }
    }
    return total;
}

int main() {
    cin>> n;
    cout<<dfs(0);
}
