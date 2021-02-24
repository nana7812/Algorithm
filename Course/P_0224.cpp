#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
//#include <set>
using  namespace  std;

const int MAX = 201;
int n,m;
int parent[MAX];

//부모노드를 찾는 함수
int getParent(int x){
    if(parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);
}

//두 부모 노드를 합치는 합수
void unionParent(int a, int b){
//    a = getParent(parent,a);
//    b= getParent(parent,b);
    if(a < b) parent[b] = a;
    else parent[a] = b;
}



int main() {
    cin>> n>>m;

    int link;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin>> link;
            if(link == 1){
                int a = getParent(i);
                int b = getParent(j);
                if(a==b){
                    continue;
                }
                unionParent(a,b);
            }
        }
    }
    int temp;  bool flag = true;
    for(int i = 0; i <m; i++){
        int travel;
        cin>>travel;
       if(i == 0 ){
           temp = getParent(travel);
       }else{
           if(temp != getParent(travel)){
               flag = false;
               break;
           }
       }
    }

    if(flag == true){
        cout<<"YES"<<"\n";
    }else{
        cout<<"NO"<<"\n";
    }
    return 0;
}