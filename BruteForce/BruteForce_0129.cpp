#include <iostream>
#include <algorithm>
using  namespace  std;

const int MAX = 11;
bool check[MAX];
int w[MAX][MAX];
int ans = 987654321;
int N;

void solve(int x,int past,int sum,int start){
    if(x >= N-1){
        if(w[past][start] != 0) {
            sum += w[past][start];
            if (sum < ans) ans = sum;
        }
        return;
    }

    for(int i = 1; i <=N; i++){
        if(check[i] == false && w[past][i] != 0 ){
            check[i] = true;
            solve(x+1,i,sum+w[past][i],start);
            check[i] = false;
        }
    }
}

int main(){
    cin>> N;
    for(int i = 1; i <=N; i++){
        for(int j = 1; j <=N; j++){
            cin>>w[i][j];
        }
    }
    for(int i = 1; i<=N; i++){
        check[i] = true;
        solve(0,i,0,i);
        check[i] = false;
    }

    cout<<ans;

}