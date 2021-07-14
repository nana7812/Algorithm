#include <iostream>
#include <stdlib.h>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
#include <queue>
#include <cstring>
#include <stack>

#define MAX 100000
using namespace std;





char m[2][MAX];
bool check[2][MAX];
int N,K;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

int BFS(int a, int b){
    queue<pair<pair<int,int>,int>> q;
    q.push({{a,b},0});
   check[a][b] = true;
     while(!q.empty()){
        int qx = q.front().first.first;
        int qy = q.front().first.second;
        int qs = q.front().second;
        q.pop();
        if(qs >= N) break; //아래 주석 지우면 이 코드 지워도 됨
        for(int k = 0; k < 4; k++){
            int nx = qx + dx[k];
            int ny = qy + dy[k];
            if(nx != qx){
                ny += K;
            }
            if(ny >= N) return 1;
            if(0<= nx && nx <2 && qs< ny && ny < N){
                if(m[nx][ny] == '1' && check[nx][ny] == false){
                    q.push({{nx,ny},qs+1});
                    check[nx][ny] = true;
                }
            }
        }
    //    m[0][qs] = '0';
      //  m[1][qs] = '0';
   }
    return 0;
}


int main() {

    cin>> N>> K;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < N; j++){
            cin>> m[i][j];
        }
    }
  int ans = BFS(0,0);
    cout<<ans<<"\n";

    return 0;
}