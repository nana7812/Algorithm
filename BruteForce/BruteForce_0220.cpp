#include <iostream>
//#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
//#include <set>
using  namespace  std;

const int MAX = 21;
int N,S;
bool check[MAX];
int num[MAX];
int ans = 0;

void BruteForce(int x,int s, int e,int sum){
    if(x >= e){
       // cout<<sum;
        if(sum == S){
          //  cout<<"ok"<<" ";
            ans++;
            return;
        }else{
          //  cout<<"no"<<" ";
            return;
        }
    }

    for(int i = s; i < N; i++){
        if(check[i] == false){
            check[i] = true;
            BruteForce(x+1,i+1,e,sum+num[i]);
            check[i] = false;
        }
    }
}

int main() {
    cin>> N>>S;
    for(int i =0; i < N; i++){
        cin>> num[i];
    }
    for(int i =1; i <=N;i++){
        BruteForce(0,0,i,0);
      //  cout<<"\n";
    }
    cout<<ans;
}