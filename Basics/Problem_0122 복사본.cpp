//
// Created by 김정음 on 2021/01/22.
//
//
// Created by 김정음 on 2021/01/22.
//
#include <iostream>
using  namespace  std;
bool check[1001];

int main(){
    int n, k;
    cin>> n>> k;
    int order = 0;

    for(int i = 2; i <= n; i++){
        if(check[i] == false){
            for(int j = i; j <= n; j += i){
                check[j] = true;
                order++;
                if(order == k){
                    cout<<j;
                }
            }
        }
    }

    return 0;
}


